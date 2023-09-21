#include<stdio.h>
#include<string.h>
typedef struct Book{
    char name[20];  //书名
    int num;        //编号
    int left;       //可借数量
}Book;
typedef struct Reader{
    char name[20];  //姓名
    int num;        //编号
    char root[20];  //密码
}Reader;
typedef struct Administrator{
    char name[20];  //姓名
    int num;        //编号
    char root[20];  //密码
}Administrator;
//定义了一些全局变量，包括books数组、readers数组、administrators数组、borrowerList二维数组和borrowedBookList二维数组。其中，books数组用于存储所有的书籍信息，readers数组用于存储所有的读者信息，administrators数组用于存储所有的管理员信息，borrowerList二维数组用于存储所有借书记录，borrowedBookList二维数组用于存储每个读者所借的书籍。


        Book books[110];                    //书籍信息数组，最多存储110本书
Reader readers[110];                //读者信息数组，最多存储110个读者
Administrator administrators[10];   //管理员信息数组，最多存储10个管理员
char borrowerList[110][100];        //借阅记录数组，最多存储110条记录，每条记录最长100个字符
char borrowedBookList[110][100];    //借书记录数组，最多存储110条记录，每条记录最长100个字符
//一些函数的声明：


void ShowBook(char* bname);
void ShowReader(char* rname);
void BookLend(char *rname, char *bname);
void BookReturn(char *rname, char* bname);
void ReadBooksInfo();
void ReadReadersInfo();
void ReadAdministratorsInfo();
void UpdateBorrowerList();
void UpdateBorrowedBookList();
void UpdateBookleft();
void UpdateBooks();
void UpdateReaders();
void UpdateAdministrators();
void UpdateReroots();
void UpdateAdroots();
void AddBook(char* bname);
void DelBook(char* bname);
void AddReader(char* rname, char* reroot);
void DelReader(char* rname);
其中，ShowBook、ShowReader、BookLend和BookReturn分别用于展示书籍信息、读者信息、借书和还书；ReadBooksInfo、ReadReadersInfo和ReadAdministratorsInfo函数用于读取文件中的书籍信息、读者信息和管理员信息；UpdateBorrowerList、UpdateBorrowedBookList、UpdateBookleft、UpdateBooks、UpdateReaders、UpdateAdministrators、UpdateReroots和UpdateAdroots函数用于更新借阅记录、借书记录、书籍剩余数量、书籍信息、读者信息、管理员信息以及读者和管理员密码；AddBook和DelBook函数用于添加和删除书籍；AddReader和DelReader函数用于添加和删除读者。

//在main函数中，首先调用了ReadBooksInfo、ReadReadersInfo和ReadAdministratorsInfo函数来读取书籍信息、读者信息和管理员信息。


int main(int argc, char *argv[]) {
    system("chcp 65001");   //设置控制台编码格式为UTF-8
    ReadBooksInfo();
    ReadReadersInfo();
    ReadAdministratorsInfo();
    char *command = argv[1], *name = argv[2];
    printf("Hello, %s! Welcome to XDULibrary!\n", name);    //打印欢迎语句
   // 接下来根据用户输入的命令来选择相应的功能。如果是管理员，会先要求输入密码，验证通过后进入管理系统，可以进行展示书籍、展示读者、删除读者、删除书籍、添加读者和添加书籍等操作；如果是读者，也会要求输入密码，验证通过后进入借还书系统，可以进行展示书籍、展示读者、借书和还书等操作。


    if(!strcmp(command, "-a")){    //管理员
        char root[10];
        printf("Please enter your root:\n");
        scanf("%s", root);      //输入管理员密码
        int i, flag = 0, choice;
        for(i = 0; i < 10; i++)
            if(!strcmp(administrators[i].root, root)) flag = 1;     //验证密码是否正确
        if(!flag){
            printf("wrong root\n");
            return -1;
        }
        printf("0.exit\n1.show books\n2.show readers\n3.delete readers\n4.delete books\n5.add readers\n6.add books\n");
        while (1) {
            printf("please choose what to do:\n");
            scanf("%d", &choice);   //选择具体操作
            if (choice == 0){
                printf("exit successfully");   //退出系统
                return 0;
            }
            switch(choice){
                case 1:{
                    char bname[20];
                    printf("please enter book's name:\n");
                    scanf("%s", bname);
                    ShowBook(bname);    //展示书籍信息
                    break;
                }
                case 2:{
                    char rname[20];
                    printf("please enter reader's name:\n");
                    scanf("%s", rname);
                    ShowReader(rname);  //展示读者信息
                    break;
                }
                case 3:{
                    char rname[20];
                    printf("please enter reader's name:\n");
                    scanf("%s", rname);
                    DelReader(rname);   //删除读者
                    break;
                }
                case 4:{
                    char bname[20];
                    printf("please enter book's name:\n");
                    scanf("%s", bname);
                    DelBook(bname);     //删除书籍
                    break;
                }
                case 5:{
                    char rname[20], reroot[20];
                    printf("please enter reader's name:\n");
                    scanf("%s", rname);
                    printf("please enter reader's root:\n");
                    scanf("%s", reroot);
                    AddReader(rname, reroot);   //添加读者
                    break;
                }
                case 6:{
                    char bname[20];
                    printf("please enter book's name:\n");
                    scanf("%s", bname);
                    AddBook(bname);     //添加书籍
                    break;
                }
                default:{
                    printf("illegal input\n");  //输入不合法
                    break;
                }
            }
        }
    }
    else if (!strcmp(command, "-u")){   //读者
        char root[10];
        printf("Please enter your root:\n");
        scanf("%s", root);      //输入读者密码
        int i, flag = 0, choice;
        for(i = 0; i < 10; i++){
            if(!strcmp(readers[i].root, root)) flag = 1;     //验证密码是否正确
        }
        if(!flag){
            printf("wrong root\n");
            return -1;
        }
        printf("0.exit\n1.show books\n2.show readers\n3.lend books\n4.return books\n");
        while (1) {

            printf("please choose what to do:\n");
            scanf("%d", &choice);   //选择具体操作
            if (choice == 0){
                printf("exit successfully");   //退出系统
                return 0;
            }
            switch(choice){
                case 1:{
                    char bname[20];
                    printf("please enter book's name:\n");
                    scanf("%s", bname);
                    ShowBook(bname);    //展示书籍信息
                    break;
                }
                case 2:{
                    char rname[20];
                    printf("please enter reader's name:\n");
                    scanf("%s", rname);
                    ShowReader(rname);  //展示读者信息
                    break;
                }
                case 3:{
                    char bname[20];
                    printf("please enter book's name:\n");
                    scanf("%s", bname);
                    BookLend(name, bname);  //借书
                    break;
                }
                case 4:{
                    char bname[20];
                    printf("please enter book's name:\n");
                    scanf("%s", bname);
                    BookReturn(name, bname);    //还书
                    break;
                }
                default:{
                    printf("illegal input\n");  //输入不合法
                    break;
                }
            }
        }
    }
    else{
        printf("illegal input\n");  //输入不合法
        return -1;
    }
    return 0;
}
//打开文件并读取其中的信息
void ReadReadersInfo(){
//以只读方式打开名为"readers.txt"的文件，并返回指向文件的指针
    FILE *fp1 = fopen("readers.txt", "r");
//以只读方式打开名为"borrowedBookList.txt"的文件，并返回指向文件的指针
    FILE *fp2 = fopen("borrowedBookList.txt", "r");
//以只读方式打开名为"reroots.txt"的文件，并返回指向文件的指针
    FILE *fp3 = fopen("reroots.txt", "r");
//检查文件是否成功打开
    if(fp1 == NULL || fp2 == NULL || fp3 == NULL){
//打印系统错误信息并退出函数
        printf("system error\n");
        return;
    }
//定义字符数组t，用于存储从文件中读取的字符串
    char t[100];
//定义计数器i，用于记录读取到的行数
    int i = 0;
//使用fgets函数从文件中读取一行数据，并将其存储在字符数组t中，当读到文件末尾时停止读取。
    while(fgets(t, 100, fp1) != NULL){
//如果t的最后一个字符为换行符，则用'\0'替换
        if(t[strlen(t)-1] == '\n')	t[strlen(t)-1] = '\0';
//将读取到的读者姓名存储在结构体数组readers的名字属性中
        strcpy(readers[i].name, t);
//将读者编号存储在结构体数组readers的num属性中
        readers[i].num = i;
//递增计数器i，继续读取下一行数据
        i++;
//如果读取到"end"字符串，则说明已经读完了所有信息，停止读取并跳出循环
        if(!strcmp(t, "end"))	break;
    }
//重置计数器i，并开始读取第二个文件
    i = 0;
    while(fgets(t, 100, fp2) != NULL){
        if(t[strlen(t)-1] == '\n')	t[strlen(t)-1] = '\0';
        strcpy(borrowedBookList[i], t);
        i++;
        if(!strcmp(t, "end"))	break;
    }
    i = 0;
//读取第三个文件
    while(fgets(t, 100, fp3) != NULL){
        if(t[strlen(t)-1] == '\n')	t[strlen(t)-1] = '\0';
        strcpy(readers[i].root, t);
        i++;
        if(!strcmp(t, "end"))	break;
    }
//关闭文件
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}

//打开文件并读取其中的信息
void ReadAdministratorsInfo(){
//以只读方式打开名为"administrators.txt"的文件，并返回指向文件的指针
    FILE *fp1 = fopen("administrators.txt", "r");
//以只读方式打开名为"adroots.txt"的文件，并返回指向文件的指针
    FILE *fp2 = fopen("adroots.txt", "r");
//检查文件是否成功打开
    if(fp1 == NULL || fp2 == NULL){
//打印系统错误信息并退出函数
        printf("system error\n");
        return;
    }
//定义字符数组t，用于存储从文件中读取的字符串
    char t[100];
//定义计数器i，用于记录读取到的行数
    int i = 0;
//使用fgets函数从文件中读取一行数据，并将其存储在字符数组t中，当读到文件末尾时停止读取。
    while(fgets(t, 100, fp1) != NULL){
//如果t的最后一个字符为换行符，则用'\0'替换
        if(t[strlen(t)-1] == '\n')	t[strlen(t)-1] = '\0';
//将读取到的管理员姓名存储在结构体数组administrators的名字属性中
        strcpy(administrators[i].name, t);
//将管理员编号存储在结构体数组administrators的num属性中
        administrators[i].num = i;
//递增计数器i，继续读取下一行数据
        i++;
//如果读取到"end"字符串，则说明已经读完了所有信息，停止读取并跳出循环
        if(!strcmp(t, "end"))	break;
    }
    i = 0;
//读取第二个文件
    while(fgets(t, 100, fp2) != NULL){
        if(t[strlen(t)-1] == '\n')	t[strlen(t)-1] = '\0';
        strcpy(administrators[i].root, t);
        i++;
        if(!strcmp(t, "end"))	break;
    }
//关闭文件
    fclose(fp1);
    fclose(fp2);
}

//更新借阅者列表
void UpdateBorrowerList(){
//以写入方式打开名为"borrowerList.txt"的文件，并返回指向文件的指针
    FILE *fw = fopen("borrowerList.txt", "w");
//检查文件是否成功打开
    if(fw == NULL){
//打印系统错误信息并退出函数
        printf("system error\n");
        return;
    }
//定义计数器k，用于遍历当前的借阅者列表
    int k;
    for(k = 0; k < 100; k++){
//如果当前读取到的借阅者姓名为"no"，则写入一个换行符到文件中
        if(!strcmp(borrowerList[k], "no"))	fputc('\n', fw);
        else {
//否则将当前的借阅者姓名写入文件中
            fputs(borrowerList[k], fw);
//再写入一个换行符
            fputc('\n', fw);
        }
//如果读取到了"end"字符串，则说明已经遍历完了所有借阅者信息，停止遍历并跳出循环。
        if(!strcmp(borrowerList[k], "end"))	break;
    }
//关闭文件
    fclose(fw);
}

//更新已借阅书籍列表
void UpdateBorrowedBookList(){
//以写入方式打开名为"borrowedBookList.txt"的文件，并返回指向文件的指针
    FILE *fw = fopen("borrowedBookList.txt", "w");
//检查文件是否成功打开
    if(fw == NULL){
//打印系统错误信息并退出函数
        printf("system error\n");
        return;
    }
//定义计数器k，用于遍历当前的已借阅书籍列表
    int k;
    for(k = 0; k < 100; k++){
//将当前的已借阅书籍名称写入文件中
        fputs(borrowedBookList[k], fw);
//再写入一个换行符
        fputc('\n', fw);
//如果读取到了"end"字符串，则说明已经遍历完了所有已借阅书籍信息，停止遍历并跳出循环。
        if(!strcmp(borrowedBookList[k], "end"))	break;
    }
//关闭文件
    fclose(fw);
}

//更新图书剩余量
void UpdateBookleft(){
//以写入方式打开名为"booksleft.txt"的文件，并返回指向文件的指针
    FILE *fw = fopen("booksleft.txt", "w");
//检查文件是否成功打开
    if(fw == NULL){
//打印系统错误信息并退出函数
        printf("system error\n");
        return;
    }
//定义计数器k，用于遍历当前的图书列表
    int k;
    for(k = 0; k < 100; k++){
//定义字符数组x，用于将剩余图书量转换成字符串
        char x[10];
//如果当前读取到的图书剩余量为-1，则说明已经读完了所有图书信息，写入"end"字符串并跳出循环。
        if(books[k].left == -1){
            fputs("end", fw);
            break;
        }
//将当前的剩余图书量转换成字符串，存储在字符数组x中
        itoa(books[k].left, x, 10);
//将转换后的字符串写入文件中
        fputs(x, fw);
//再写入一个换行符
        fputc('\n', fw);

    }
//关闭文件
    fclose(fw);
}

//更新图书列表
void UpdateBooks(){
//以写入方式打开名为"books.txt"的文件，并返回指向文件的指针
    FILE *fw = fopen("books.txt", "w");
//检查文件是否成功打开
    if(fw == NULL){
//打印系统错误信息并退出函数
        printf("system error\n");
        return;
    }
//定义计数器i，用于遍历当前的图书列表
    int i;
    for(i = 0; i < 100; i++){
//如果读取到了"end"字符串，则说明已经遍历完了所有图书信息，写入"end"字符串并跳出循环。
        if(!strcmp(books[i].name, "end")){
            fputs("end", fw);
            fclose(fw);
            return;
        }
//将当前的图书名称写入文件中
        fputs(books[i].name, fw);
//再写入一个换行符
        fputc('\n', fw);
    }
}

//更新读者列表
void UpdateReaders(){
//以写入方式打开名为"readers.txt"的文件，并返回指向文件的指针
    FILE *fw = fopen("readers.txt", "w");
//检查文件是否成功打开
    if(fw == NULL){
//打印系统错误信息并退出函数
        printf("system error\n");
        return;
    }
//定义计数器i，用于遍历当前的读者列表
    int i;
    for(i = 0; i < 100; i++){
//如果读取到了"end"字符串，则说明已经遍历完了所有读者信息，写入"end"字符串并跳出循环。
        if(!strcmp(readers[i].name, "end")){
            fputs("end", fw);
            fclose(fw);
            return;
        }
//将当前的读者姓名写入文件中
        fputs(readers[i].name, fw);
//再写入一个换行符
        fputc('\n', fw);
    }
}

//更新管理员列表
void UpdateAdministrators(){
//以写入方式打开名为"administrators.txt"的文件，并返回指向文件的指针
    FILE *fw = fopen("administrators.txt", "w");
//检查文件是否成功打开
    if(fw == NULL){//打印系统错误信息并退出函数
        printf("system error\n");
        return;
    }
//定义计数器i，用于遍历当前的管理员列表
    int i;
    for(i = 0; i < 100; i++){
        //如果读取到了"end"字符串，则说明已经遍历完了所有管理员信息，写入"end"字符串并跳出循环。
        if(!strcmp(administrators[i].name, "end")){
            fputs("end", fw);
            fclose(fw);
            return;
        }
        //将当前的管理员姓名写入文件中
        fputs(administrators[i].name, fw);
        //再写入一个换行符
        fputc('\n', fw);
    }
}






// 更新借阅者信息列表
void UpdateReroots(){
// 打开文件（以写入方式）
    FILE *fw = fopen("reroots.txt", "w");
    if(fw == NULL){ // 如果打开文件失败，则提示错误并退出函数
        printf("system error\n");
        return;
    }

// 遍历所有借阅者
    int i;
    for(i = 0; i < 100; i++){
        if(!strcmp(readers[i].root, "end")){ // 如果借阅者信息列表已经遍历完，则在文件中输出“end”并关闭文件
            fputs("end", fw);
            fclose(fw);
            return;
        }
        // 否则，将该借阅者的根节点名称写入文件，并在末尾添加换行符
        fputs(readers[i].root, fw);
        fputc('\n', fw);
    }
}

// 更新管理员信息列表
void UpdateAdroots(){
// 打开文件（以写入方式）
    FILE *fw = fopen("adroots.txt", "w");
    if(fw == NULL){ // 如果打开文件失败，则提示错误并退出函数
        printf("system error\n");
        return;
    }

// 遍历所有管理员
    int i;
    for(i = 0; i < 100; i++){
        if(!strcmp(administrators[i].root, "end")){ // 如果管理员信息列表已经遍历完，则在文件中输出“end”并关闭文件
            fputs("end", fw);
            fclose(fw);
            return;
        }
        // 否则，将该管理员的根节点名称写入文件，并在末尾添加换行符
        fputs(administrators[i].root, fw);
        fputc('\n', fw);
    }
}

// 展示某本书籍的详细信息
void ShowBook(char* bname){
    int i;
    for(i = 0; i < 100; i++){
        if(!strcmp(bname, books[i].name)){ // 如果找到了该书籍
// 输出该书籍的相关信息
            printf("name: %s\n", books[i].name);
            printf("num: %d\n", books[i].num);
            printf("left: %d\n", books[i].left);
            printf("the borrowers: %s\n", borrowerList[i]);
        }
        if(!strcmp(books[i].name, "end"))	break; // 如果已经遍历完了所有书籍，则退出循环
    }
}

// 展示某个借阅者的详细信息
void ShowReader(char* rname){
    int i;
    for(i = 0; i < 100; i++){
        if(!strcmp(rname, readers[i].name)){ // 如果找到了该借阅者
// 输出该借阅者的相关信息
            printf("name: %s\n", readers[i].name);
            printf("num: %d\n", readers[i].num);
            printf("borrowed books: %s\n", borrowedBookList[i]);
        }
        if(!strcmp(books[i].name, "end"))	break; // 如果已经遍历完了所有书籍，则退出循环
    }
}

// 借书操作
void BookLend(char *rname, char *bname){
    int i, flag = 0;
    for(i = 0; i < 100; i++){
        if(!strcmp(books[i].name, bname)){ // 如果找到了要借的书籍
            if(books[i].left == 0){ // 如果该书籍已经被借出，则提示用户并退出函数
                printf("sorry, the book is borrowed out\n");
                return;
            }else{ // 否则，进行借书操作
                books[i].left--; // 该书籍剩余数量减1

                // 更新该书籍的借阅者列表
                if(!strcmp(borrowerList[i], "end")){ // 如果该书籍没有被借过，则将该借阅者的姓名加入借阅者列表
                    strcpy(borrowerList[i], rname);
                    strcpy(borrowerList[i+1], "end");
                }else{ // 否则，在该书籍的借阅者列表末尾加入该借阅者的姓名
                    strcat(borrowerList[i], " ");
                    strcat(borrowerList[i], rname);
                }

                // 更新该借阅者的已借书籍列表
                int j;
                for(j = 0; j < 100; j++){
                    if(!strcmp(readers[j].name, rname)){ // 找到该借阅者
                        if(!strcmp(borrowedBookList[j], "end")){ // 如果该借阅者没有借过书，则将该书籍的名称加入该借阅者的已借书籍列表
                            strcpy(borrowedBookList[j], bname);
                            strcpy(borrowedBookList[j+1], "end");
                        }else{ // 否则，在该借阅者的已借书籍列表末尾加入该书籍的名称
                            strcat(borrowedBookList[j], " ");
                            strcat(borrowedBookList[j], bname);
                        }
                    }
                }
                flag = 1;
                break;
            }
        }
    }

// 更新相关信息并提示用户操作成功或失败
    UpdateBorrowerList();
    UpdateBorrowedBookList();
    UpdateBookleft();
    if(flag)	printf("success\n");
    else	printf("fail\n");
    ReadBooksInfo();
    ReadReadersInfo();
}

// 还书操作
void BookReturn(char rname, char bname){
    int i, flag = 0;
    for(i = 0; i < 100; i++){
        if(!strcmp(books[i].name, bname)){ // 如果找到了要还的书籍
            books[i].left++; // 该书籍剩余数量加1

            // 移除该借阅者在该书籍的借阅者列表中的姓名
            char *des1 = strstr(borrowerList[i], rname), *des2 = strstr(borrowerList[i], rname);
            char p[100];
            des1 += strlen(rname);
            if(des1 != NULL){
                strcpy(p, des1);
                strcpy(des2, p);
            }

            // 移除该书籍在该借阅者的已借书籍列表中的名称
            int j;
            for(j = 0; j < 100; j++){
                if(!strcmp(readers[j].name, rname)){ // 找到该借阅者
                    char *des3 = strstr(borrowedBookList[j], bname), *des4 = strstr(borrowedBookList[j], bname);
                    char q[100];
                    des3 += strlen(bname);
                    if(des3 != NULL){
                        strcpy(q, des3);
                        strcpy(des4, q);
                    }
                }
            }
            flag = 1;
            break;
        }
    }

// 更新相关信息并提示用户操作成功或失败
    UpdateBorrowerList();
    UpdateBorrowedBookList();
    UpdateBookleft();
    if(flag)	printf("success\n");
    else	printf("fail\n");
    ReadBooksInfo();
    ReadReadersInfo();
}
void AddBook(char* bname){
// 添加图书
    int i, flag = 0;
    for(i = 0; i < 100; i++){
// 遍历books数组，找到一个空槽位
        if(!strcmp(books[i].name, "end")){
// 将新的图书信息添加到books数组中
            strcpy(books[i].name, bname);
            books[i].num = i;
            books[i].left = 3;
// books数组中最后一个元素为"end"，表示数组结束标志，需要将其替换为新的标志
            strcpy(books[i+1].name, "end");
// borrowerList数组记录了每本书的借阅情况，同样需要更新
            strcpy(borrowerList[i], "no");
            strcpy(borrowerList[i+1], "end");
// 图书被添加后立即标记为不可借出
            books[i+1].left = -1;
            flag = 1;
            break;
        }
    }
// 更新books数组中各本书的剩余数目
    UpdateBookleft();
// 更新books数组和borrowerList数组的文件存储
    UpdateBooks();
    UpdateBorrowerList();
    if(flag)	printf("success\n");
    else	printf("fail\n");
}

void DelBook(char* bname){
// 删除图书
    int i, flag = 0;
    for(i = 0; i < 100; i++){
// 遍历books数组，查找指定名字的图书
        if(!strcmp(books[i].name, bname)){
// 判断图书是否可借
            if(books[i].left != 3){
                printf("fail\n");
                return;
            }
// 标记图书为已删除状态
            strcpy(books[i].name, "null");
            books[i].left = 0;
            flag = 1;
            break;
        }
    }
// 更新books数组中各本书的剩余数目
    UpdateBookleft();
// 更新books数组的文件存储
    UpdateBooks();
    if(flag)	printf("success\n");
    else	printf("fail\n");
}

void AddReader(char* rname, char* reroot){
// 添加读者
    int i, flag = 0;
    for(i = 0; i < 100; i++){
// 遍历readers数组，找到一个空槽位
        if(!strcmp(readers[i].name, "end")){
// 将新的读者信息添加到readers数组中
            strcpy(readers[i].name, rname);
            strcpy(readers[i].root, reroot);
            readers[i].num = i;
// readers数组中最后一个元素为"end"，表示数组结束标志，需要将其替换为新的标志
            strcpy(readers[i+1].name, "end");
            strcpy(readers[i+1].root, "end");
            flag = 1;
            break;
        }
    }
// 更新readers数组和reroots数组的文件存储
    UpdateReaders();
    UpdateReroots();
    if(flag)	printf("success\n");
    else	printf("fail\n");
}

void DelReader(char* rname){
// 删除读者
    int i, flag = 0;
    for(i = 0; i < 100; i++){
// 遍历readers数组，查找指定名字的读者
        if(!strcmp(readers[i].name, rname)){
// 判断读者是否有未归还的图书
            if(!strcmp(borrowedBookList[i], "null")){
                printf("fail\n");
                return;
            }
// 标记读者为已删除状态
            strcpy(readers[i].name, "null");
            flag = 1;
            break;
        }
    }
// 更新readers数组的文件存储
    UpdateReaders();
    if(flag)	printf("success\n");
    else	printf("fail\n");
}