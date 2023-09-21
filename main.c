#include<stdio.h>
#include<string.h>
typedef struct Book{
    char name[20];  //����
    int num;        //���
    int left;       //�ɽ�����
}Book;
typedef struct Reader{
    char name[20];  //����
    int num;        //���
    char root[20];  //����
}Reader;
typedef struct Administrator{
    char name[20];  //����
    int num;        //���
    char root[20];  //����
}Administrator;
//������һЩȫ�ֱ���������books���顢readers���顢administrators���顢borrowerList��ά�����borrowedBookList��ά���顣���У�books�������ڴ洢���е��鼮��Ϣ��readers�������ڴ洢���еĶ�����Ϣ��administrators�������ڴ洢���еĹ���Ա��Ϣ��borrowerList��ά�������ڴ洢���н����¼��borrowedBookList��ά�������ڴ洢ÿ������������鼮��


        Book books[110];                    //�鼮��Ϣ���飬���洢110����
Reader readers[110];                //������Ϣ���飬���洢110������
Administrator administrators[10];   //����Ա��Ϣ���飬���洢10������Ա
char borrowerList[110][100];        //���ļ�¼���飬���洢110����¼��ÿ����¼�100���ַ�
char borrowedBookList[110][100];    //�����¼���飬���洢110����¼��ÿ����¼�100���ַ�
//һЩ������������


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
���У�ShowBook��ShowReader��BookLend��BookReturn�ֱ�����չʾ�鼮��Ϣ��������Ϣ������ͻ��飻ReadBooksInfo��ReadReadersInfo��ReadAdministratorsInfo�������ڶ�ȡ�ļ��е��鼮��Ϣ��������Ϣ�͹���Ա��Ϣ��UpdateBorrowerList��UpdateBorrowedBookList��UpdateBookleft��UpdateBooks��UpdateReaders��UpdateAdministrators��UpdateReroots��UpdateAdroots�������ڸ��½��ļ�¼�������¼���鼮ʣ���������鼮��Ϣ��������Ϣ������Ա��Ϣ�Լ����ߺ͹���Ա���룻AddBook��DelBook����������Ӻ�ɾ���鼮��AddReader��DelReader����������Ӻ�ɾ�����ߡ�

//��main�����У����ȵ�����ReadBooksInfo��ReadReadersInfo��ReadAdministratorsInfo��������ȡ�鼮��Ϣ��������Ϣ�͹���Ա��Ϣ��


int main(int argc, char *argv[]) {
    system("chcp 65001");   //���ÿ���̨�����ʽΪUTF-8
    ReadBooksInfo();
    ReadReadersInfo();
    ReadAdministratorsInfo();
    char *command = argv[1], *name = argv[2];
    printf("Hello, %s! Welcome to XDULibrary!\n", name);    //��ӡ��ӭ���
   // �����������û������������ѡ����Ӧ�Ĺ��ܡ�����ǹ���Ա������Ҫ���������룬��֤ͨ����������ϵͳ�����Խ���չʾ�鼮��չʾ���ߡ�ɾ�����ߡ�ɾ���鼮����Ӷ��ߺ�����鼮�Ȳ���������Ƕ��ߣ�Ҳ��Ҫ���������룬��֤ͨ�������軹��ϵͳ�����Խ���չʾ�鼮��չʾ���ߡ�����ͻ���Ȳ�����


    if(!strcmp(command, "-a")){    //����Ա
        char root[10];
        printf("Please enter your root:\n");
        scanf("%s", root);      //�������Ա����
        int i, flag = 0, choice;
        for(i = 0; i < 10; i++)
            if(!strcmp(administrators[i].root, root)) flag = 1;     //��֤�����Ƿ���ȷ
        if(!flag){
            printf("wrong root\n");
            return -1;
        }
        printf("0.exit\n1.show books\n2.show readers\n3.delete readers\n4.delete books\n5.add readers\n6.add books\n");
        while (1) {
            printf("please choose what to do:\n");
            scanf("%d", &choice);   //ѡ��������
            if (choice == 0){
                printf("exit successfully");   //�˳�ϵͳ
                return 0;
            }
            switch(choice){
                case 1:{
                    char bname[20];
                    printf("please enter book's name:\n");
                    scanf("%s", bname);
                    ShowBook(bname);    //չʾ�鼮��Ϣ
                    break;
                }
                case 2:{
                    char rname[20];
                    printf("please enter reader's name:\n");
                    scanf("%s", rname);
                    ShowReader(rname);  //չʾ������Ϣ
                    break;
                }
                case 3:{
                    char rname[20];
                    printf("please enter reader's name:\n");
                    scanf("%s", rname);
                    DelReader(rname);   //ɾ������
                    break;
                }
                case 4:{
                    char bname[20];
                    printf("please enter book's name:\n");
                    scanf("%s", bname);
                    DelBook(bname);     //ɾ���鼮
                    break;
                }
                case 5:{
                    char rname[20], reroot[20];
                    printf("please enter reader's name:\n");
                    scanf("%s", rname);
                    printf("please enter reader's root:\n");
                    scanf("%s", reroot);
                    AddReader(rname, reroot);   //��Ӷ���
                    break;
                }
                case 6:{
                    char bname[20];
                    printf("please enter book's name:\n");
                    scanf("%s", bname);
                    AddBook(bname);     //����鼮
                    break;
                }
                default:{
                    printf("illegal input\n");  //���벻�Ϸ�
                    break;
                }
            }
        }
    }
    else if (!strcmp(command, "-u")){   //����
        char root[10];
        printf("Please enter your root:\n");
        scanf("%s", root);      //�����������
        int i, flag = 0, choice;
        for(i = 0; i < 10; i++){
            if(!strcmp(readers[i].root, root)) flag = 1;     //��֤�����Ƿ���ȷ
        }
        if(!flag){
            printf("wrong root\n");
            return -1;
        }
        printf("0.exit\n1.show books\n2.show readers\n3.lend books\n4.return books\n");
        while (1) {

            printf("please choose what to do:\n");
            scanf("%d", &choice);   //ѡ��������
            if (choice == 0){
                printf("exit successfully");   //�˳�ϵͳ
                return 0;
            }
            switch(choice){
                case 1:{
                    char bname[20];
                    printf("please enter book's name:\n");
                    scanf("%s", bname);
                    ShowBook(bname);    //չʾ�鼮��Ϣ
                    break;
                }
                case 2:{
                    char rname[20];
                    printf("please enter reader's name:\n");
                    scanf("%s", rname);
                    ShowReader(rname);  //չʾ������Ϣ
                    break;
                }
                case 3:{
                    char bname[20];
                    printf("please enter book's name:\n");
                    scanf("%s", bname);
                    BookLend(name, bname);  //����
                    break;
                }
                case 4:{
                    char bname[20];
                    printf("please enter book's name:\n");
                    scanf("%s", bname);
                    BookReturn(name, bname);    //����
                    break;
                }
                default:{
                    printf("illegal input\n");  //���벻�Ϸ�
                    break;
                }
            }
        }
    }
    else{
        printf("illegal input\n");  //���벻�Ϸ�
        return -1;
    }
    return 0;
}
//���ļ�����ȡ���е���Ϣ
void ReadReadersInfo(){
//��ֻ����ʽ����Ϊ"readers.txt"���ļ���������ָ���ļ���ָ��
    FILE *fp1 = fopen("readers.txt", "r");
//��ֻ����ʽ����Ϊ"borrowedBookList.txt"���ļ���������ָ���ļ���ָ��
    FILE *fp2 = fopen("borrowedBookList.txt", "r");
//��ֻ����ʽ����Ϊ"reroots.txt"���ļ���������ָ���ļ���ָ��
    FILE *fp3 = fopen("reroots.txt", "r");
//����ļ��Ƿ�ɹ���
    if(fp1 == NULL || fp2 == NULL || fp3 == NULL){
//��ӡϵͳ������Ϣ���˳�����
        printf("system error\n");
        return;
    }
//�����ַ�����t�����ڴ洢���ļ��ж�ȡ���ַ���
    char t[100];
//���������i�����ڼ�¼��ȡ��������
    int i = 0;
//ʹ��fgets�������ļ��ж�ȡһ�����ݣ�������洢���ַ�����t�У��������ļ�ĩβʱֹͣ��ȡ��
    while(fgets(t, 100, fp1) != NULL){
//���t�����һ���ַ�Ϊ���з�������'\0'�滻
        if(t[strlen(t)-1] == '\n')	t[strlen(t)-1] = '\0';
//����ȡ���Ķ��������洢�ڽṹ������readers������������
        strcpy(readers[i].name, t);
//�����߱�Ŵ洢�ڽṹ������readers��num������
        readers[i].num = i;
//����������i��������ȡ��һ������
        i++;
//�����ȡ��"end"�ַ�������˵���Ѿ�������������Ϣ��ֹͣ��ȡ������ѭ��
        if(!strcmp(t, "end"))	break;
    }
//���ü�����i������ʼ��ȡ�ڶ����ļ�
    i = 0;
    while(fgets(t, 100, fp2) != NULL){
        if(t[strlen(t)-1] == '\n')	t[strlen(t)-1] = '\0';
        strcpy(borrowedBookList[i], t);
        i++;
        if(!strcmp(t, "end"))	break;
    }
    i = 0;
//��ȡ�������ļ�
    while(fgets(t, 100, fp3) != NULL){
        if(t[strlen(t)-1] == '\n')	t[strlen(t)-1] = '\0';
        strcpy(readers[i].root, t);
        i++;
        if(!strcmp(t, "end"))	break;
    }
//�ر��ļ�
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}

//���ļ�����ȡ���е���Ϣ
void ReadAdministratorsInfo(){
//��ֻ����ʽ����Ϊ"administrators.txt"���ļ���������ָ���ļ���ָ��
    FILE *fp1 = fopen("administrators.txt", "r");
//��ֻ����ʽ����Ϊ"adroots.txt"���ļ���������ָ���ļ���ָ��
    FILE *fp2 = fopen("adroots.txt", "r");
//����ļ��Ƿ�ɹ���
    if(fp1 == NULL || fp2 == NULL){
//��ӡϵͳ������Ϣ���˳�����
        printf("system error\n");
        return;
    }
//�����ַ�����t�����ڴ洢���ļ��ж�ȡ���ַ���
    char t[100];
//���������i�����ڼ�¼��ȡ��������
    int i = 0;
//ʹ��fgets�������ļ��ж�ȡһ�����ݣ�������洢���ַ�����t�У��������ļ�ĩβʱֹͣ��ȡ��
    while(fgets(t, 100, fp1) != NULL){
//���t�����һ���ַ�Ϊ���з�������'\0'�滻
        if(t[strlen(t)-1] == '\n')	t[strlen(t)-1] = '\0';
//����ȡ���Ĺ���Ա�����洢�ڽṹ������administrators������������
        strcpy(administrators[i].name, t);
//������Ա��Ŵ洢�ڽṹ������administrators��num������
        administrators[i].num = i;
//����������i��������ȡ��һ������
        i++;
//�����ȡ��"end"�ַ�������˵���Ѿ�������������Ϣ��ֹͣ��ȡ������ѭ��
        if(!strcmp(t, "end"))	break;
    }
    i = 0;
//��ȡ�ڶ����ļ�
    while(fgets(t, 100, fp2) != NULL){
        if(t[strlen(t)-1] == '\n')	t[strlen(t)-1] = '\0';
        strcpy(administrators[i].root, t);
        i++;
        if(!strcmp(t, "end"))	break;
    }
//�ر��ļ�
    fclose(fp1);
    fclose(fp2);
}

//���½������б�
void UpdateBorrowerList(){
//��д�뷽ʽ����Ϊ"borrowerList.txt"���ļ���������ָ���ļ���ָ��
    FILE *fw = fopen("borrowerList.txt", "w");
//����ļ��Ƿ�ɹ���
    if(fw == NULL){
//��ӡϵͳ������Ϣ���˳�����
        printf("system error\n");
        return;
    }
//���������k�����ڱ�����ǰ�Ľ������б�
    int k;
    for(k = 0; k < 100; k++){
//�����ǰ��ȡ���Ľ���������Ϊ"no"����д��һ�����з����ļ���
        if(!strcmp(borrowerList[k], "no"))	fputc('\n', fw);
        else {
//���򽫵�ǰ�Ľ���������д���ļ���
            fputs(borrowerList[k], fw);
//��д��һ�����з�
            fputc('\n', fw);
        }
//�����ȡ����"end"�ַ�������˵���Ѿ������������н�������Ϣ��ֹͣ����������ѭ����
        if(!strcmp(borrowerList[k], "end"))	break;
    }
//�ر��ļ�
    fclose(fw);
}

//�����ѽ����鼮�б�
void UpdateBorrowedBookList(){
//��д�뷽ʽ����Ϊ"borrowedBookList.txt"���ļ���������ָ���ļ���ָ��
    FILE *fw = fopen("borrowedBookList.txt", "w");
//����ļ��Ƿ�ɹ���
    if(fw == NULL){
//��ӡϵͳ������Ϣ���˳�����
        printf("system error\n");
        return;
    }
//���������k�����ڱ�����ǰ���ѽ����鼮�б�
    int k;
    for(k = 0; k < 100; k++){
//����ǰ���ѽ����鼮����д���ļ���
        fputs(borrowedBookList[k], fw);
//��д��һ�����з�
        fputc('\n', fw);
//�����ȡ����"end"�ַ�������˵���Ѿ��������������ѽ����鼮��Ϣ��ֹͣ����������ѭ����
        if(!strcmp(borrowedBookList[k], "end"))	break;
    }
//�ر��ļ�
    fclose(fw);
}

//����ͼ��ʣ����
void UpdateBookleft(){
//��д�뷽ʽ����Ϊ"booksleft.txt"���ļ���������ָ���ļ���ָ��
    FILE *fw = fopen("booksleft.txt", "w");
//����ļ��Ƿ�ɹ���
    if(fw == NULL){
//��ӡϵͳ������Ϣ���˳�����
        printf("system error\n");
        return;
    }
//���������k�����ڱ�����ǰ��ͼ���б�
    int k;
    for(k = 0; k < 100; k++){
//�����ַ�����x�����ڽ�ʣ��ͼ����ת�����ַ���
        char x[10];
//�����ǰ��ȡ����ͼ��ʣ����Ϊ-1����˵���Ѿ�����������ͼ����Ϣ��д��"end"�ַ���������ѭ����
        if(books[k].left == -1){
            fputs("end", fw);
            break;
        }
//����ǰ��ʣ��ͼ����ת�����ַ������洢���ַ�����x��
        itoa(books[k].left, x, 10);
//��ת������ַ���д���ļ���
        fputs(x, fw);
//��д��һ�����з�
        fputc('\n', fw);

    }
//�ر��ļ�
    fclose(fw);
}

//����ͼ���б�
void UpdateBooks(){
//��д�뷽ʽ����Ϊ"books.txt"���ļ���������ָ���ļ���ָ��
    FILE *fw = fopen("books.txt", "w");
//����ļ��Ƿ�ɹ���
    if(fw == NULL){
//��ӡϵͳ������Ϣ���˳�����
        printf("system error\n");
        return;
    }
//���������i�����ڱ�����ǰ��ͼ���б�
    int i;
    for(i = 0; i < 100; i++){
//�����ȡ����"end"�ַ�������˵���Ѿ�������������ͼ����Ϣ��д��"end"�ַ���������ѭ����
        if(!strcmp(books[i].name, "end")){
            fputs("end", fw);
            fclose(fw);
            return;
        }
//����ǰ��ͼ������д���ļ���
        fputs(books[i].name, fw);
//��д��һ�����з�
        fputc('\n', fw);
    }
}

//���¶����б�
void UpdateReaders(){
//��д�뷽ʽ����Ϊ"readers.txt"���ļ���������ָ���ļ���ָ��
    FILE *fw = fopen("readers.txt", "w");
//����ļ��Ƿ�ɹ���
    if(fw == NULL){
//��ӡϵͳ������Ϣ���˳�����
        printf("system error\n");
        return;
    }
//���������i�����ڱ�����ǰ�Ķ����б�
    int i;
    for(i = 0; i < 100; i++){
//�����ȡ����"end"�ַ�������˵���Ѿ������������ж�����Ϣ��д��"end"�ַ���������ѭ����
        if(!strcmp(readers[i].name, "end")){
            fputs("end", fw);
            fclose(fw);
            return;
        }
//����ǰ�Ķ�������д���ļ���
        fputs(readers[i].name, fw);
//��д��һ�����з�
        fputc('\n', fw);
    }
}

//���¹���Ա�б�
void UpdateAdministrators(){
//��д�뷽ʽ����Ϊ"administrators.txt"���ļ���������ָ���ļ���ָ��
    FILE *fw = fopen("administrators.txt", "w");
//����ļ��Ƿ�ɹ���
    if(fw == NULL){//��ӡϵͳ������Ϣ���˳�����
        printf("system error\n");
        return;
    }
//���������i�����ڱ�����ǰ�Ĺ���Ա�б�
    int i;
    for(i = 0; i < 100; i++){
        //�����ȡ����"end"�ַ�������˵���Ѿ������������й���Ա��Ϣ��д��"end"�ַ���������ѭ����
        if(!strcmp(administrators[i].name, "end")){
            fputs("end", fw);
            fclose(fw);
            return;
        }
        //����ǰ�Ĺ���Ա����д���ļ���
        fputs(administrators[i].name, fw);
        //��д��һ�����з�
        fputc('\n', fw);
    }
}






// ���½�������Ϣ�б�
void UpdateReroots(){
// ���ļ�����д�뷽ʽ��
    FILE *fw = fopen("reroots.txt", "w");
    if(fw == NULL){ // ������ļ�ʧ�ܣ�����ʾ�����˳�����
        printf("system error\n");
        return;
    }

// �������н�����
    int i;
    for(i = 0; i < 100; i++){
        if(!strcmp(readers[i].root, "end")){ // �����������Ϣ�б��Ѿ������꣬�����ļ��������end�����ر��ļ�
            fputs("end", fw);
            fclose(fw);
            return;
        }
        // ���򣬽��ý����ߵĸ��ڵ�����д���ļ�������ĩβ��ӻ��з�
        fputs(readers[i].root, fw);
        fputc('\n', fw);
    }
}

// ���¹���Ա��Ϣ�б�
void UpdateAdroots(){
// ���ļ�����д�뷽ʽ��
    FILE *fw = fopen("adroots.txt", "w");
    if(fw == NULL){ // ������ļ�ʧ�ܣ�����ʾ�����˳�����
        printf("system error\n");
        return;
    }

// �������й���Ա
    int i;
    for(i = 0; i < 100; i++){
        if(!strcmp(administrators[i].root, "end")){ // �������Ա��Ϣ�б��Ѿ������꣬�����ļ��������end�����ر��ļ�
            fputs("end", fw);
            fclose(fw);
            return;
        }
        // ���򣬽��ù���Ա�ĸ��ڵ�����д���ļ�������ĩβ��ӻ��з�
        fputs(administrators[i].root, fw);
        fputc('\n', fw);
    }
}

// չʾĳ���鼮����ϸ��Ϣ
void ShowBook(char* bname){
    int i;
    for(i = 0; i < 100; i++){
        if(!strcmp(bname, books[i].name)){ // ����ҵ��˸��鼮
// ������鼮�������Ϣ
            printf("name: %s\n", books[i].name);
            printf("num: %d\n", books[i].num);
            printf("left: %d\n", books[i].left);
            printf("the borrowers: %s\n", borrowerList[i]);
        }
        if(!strcmp(books[i].name, "end"))	break; // ����Ѿ��������������鼮�����˳�ѭ��
    }
}

// չʾĳ�������ߵ���ϸ��Ϣ
void ShowReader(char* rname){
    int i;
    for(i = 0; i < 100; i++){
        if(!strcmp(rname, readers[i].name)){ // ����ҵ��˸ý�����
// ����ý����ߵ������Ϣ
            printf("name: %s\n", readers[i].name);
            printf("num: %d\n", readers[i].num);
            printf("borrowed books: %s\n", borrowedBookList[i]);
        }
        if(!strcmp(books[i].name, "end"))	break; // ����Ѿ��������������鼮�����˳�ѭ��
    }
}

// �������
void BookLend(char *rname, char *bname){
    int i, flag = 0;
    for(i = 0; i < 100; i++){
        if(!strcmp(books[i].name, bname)){ // ����ҵ���Ҫ����鼮
            if(books[i].left == 0){ // ������鼮�Ѿ������������ʾ�û����˳�����
                printf("sorry, the book is borrowed out\n");
                return;
            }else{ // ���򣬽��н������
                books[i].left--; // ���鼮ʣ��������1

                // ���¸��鼮�Ľ������б�
                if(!strcmp(borrowerList[i], "end")){ // ������鼮û�б�������򽫸ý����ߵ���������������б�
                    strcpy(borrowerList[i], rname);
                    strcpy(borrowerList[i+1], "end");
                }else{ // �����ڸ��鼮�Ľ������б�ĩβ����ý����ߵ�����
                    strcat(borrowerList[i], " ");
                    strcat(borrowerList[i], rname);
                }

                // ���¸ý����ߵ��ѽ��鼮�б�
                int j;
                for(j = 0; j < 100; j++){
                    if(!strcmp(readers[j].name, rname)){ // �ҵ��ý�����
                        if(!strcmp(borrowedBookList[j], "end")){ // ����ý�����û�н���飬�򽫸��鼮�����Ƽ���ý����ߵ��ѽ��鼮�б�
                            strcpy(borrowedBookList[j], bname);
                            strcpy(borrowedBookList[j+1], "end");
                        }else{ // �����ڸý����ߵ��ѽ��鼮�б�ĩβ������鼮������
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

// ���������Ϣ����ʾ�û������ɹ���ʧ��
    UpdateBorrowerList();
    UpdateBorrowedBookList();
    UpdateBookleft();
    if(flag)	printf("success\n");
    else	printf("fail\n");
    ReadBooksInfo();
    ReadReadersInfo();
}

// �������
void BookReturn(char rname, char bname){
    int i, flag = 0;
    for(i = 0; i < 100; i++){
        if(!strcmp(books[i].name, bname)){ // ����ҵ���Ҫ�����鼮
            books[i].left++; // ���鼮ʣ��������1

            // �Ƴ��ý������ڸ��鼮�Ľ������б��е�����
            char *des1 = strstr(borrowerList[i], rname), *des2 = strstr(borrowerList[i], rname);
            char p[100];
            des1 += strlen(rname);
            if(des1 != NULL){
                strcpy(p, des1);
                strcpy(des2, p);
            }

            // �Ƴ����鼮�ڸý����ߵ��ѽ��鼮�б��е�����
            int j;
            for(j = 0; j < 100; j++){
                if(!strcmp(readers[j].name, rname)){ // �ҵ��ý�����
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

// ���������Ϣ����ʾ�û������ɹ���ʧ��
    UpdateBorrowerList();
    UpdateBorrowedBookList();
    UpdateBookleft();
    if(flag)	printf("success\n");
    else	printf("fail\n");
    ReadBooksInfo();
    ReadReadersInfo();
}
void AddBook(char* bname){
// ���ͼ��
    int i, flag = 0;
    for(i = 0; i < 100; i++){
// ����books���飬�ҵ�һ���ղ�λ
        if(!strcmp(books[i].name, "end")){
// ���µ�ͼ����Ϣ��ӵ�books������
            strcpy(books[i].name, bname);
            books[i].num = i;
            books[i].left = 3;
// books���������һ��Ԫ��Ϊ"end"����ʾ���������־����Ҫ�����滻Ϊ�µı�־
            strcpy(books[i+1].name, "end");
// borrowerList�����¼��ÿ����Ľ��������ͬ����Ҫ����
            strcpy(borrowerList[i], "no");
            strcpy(borrowerList[i+1], "end");
// ͼ�鱻��Ӻ��������Ϊ���ɽ��
            books[i+1].left = -1;
            flag = 1;
            break;
        }
    }
// ����books�����и������ʣ����Ŀ
    UpdateBookleft();
// ����books�����borrowerList������ļ��洢
    UpdateBooks();
    UpdateBorrowerList();
    if(flag)	printf("success\n");
    else	printf("fail\n");
}

void DelBook(char* bname){
// ɾ��ͼ��
    int i, flag = 0;
    for(i = 0; i < 100; i++){
// ����books���飬����ָ�����ֵ�ͼ��
        if(!strcmp(books[i].name, bname)){
// �ж�ͼ���Ƿ�ɽ�
            if(books[i].left != 3){
                printf("fail\n");
                return;
            }
// ���ͼ��Ϊ��ɾ��״̬
            strcpy(books[i].name, "null");
            books[i].left = 0;
            flag = 1;
            break;
        }
    }
// ����books�����и������ʣ����Ŀ
    UpdateBookleft();
// ����books������ļ��洢
    UpdateBooks();
    if(flag)	printf("success\n");
    else	printf("fail\n");
}

void AddReader(char* rname, char* reroot){
// ��Ӷ���
    int i, flag = 0;
    for(i = 0; i < 100; i++){
// ����readers���飬�ҵ�һ���ղ�λ
        if(!strcmp(readers[i].name, "end")){
// ���µĶ�����Ϣ��ӵ�readers������
            strcpy(readers[i].name, rname);
            strcpy(readers[i].root, reroot);
            readers[i].num = i;
// readers���������һ��Ԫ��Ϊ"end"����ʾ���������־����Ҫ�����滻Ϊ�µı�־
            strcpy(readers[i+1].name, "end");
            strcpy(readers[i+1].root, "end");
            flag = 1;
            break;
        }
    }
// ����readers�����reroots������ļ��洢
    UpdateReaders();
    UpdateReroots();
    if(flag)	printf("success\n");
    else	printf("fail\n");
}

void DelReader(char* rname){
// ɾ������
    int i, flag = 0;
    for(i = 0; i < 100; i++){
// ����readers���飬����ָ�����ֵĶ���
        if(!strcmp(readers[i].name, rname)){
// �ж϶����Ƿ���δ�黹��ͼ��
            if(!strcmp(borrowedBookList[i], "null")){
                printf("fail\n");
                return;
            }
// ��Ƕ���Ϊ��ɾ��״̬
            strcpy(readers[i].name, "null");
            flag = 1;
            break;
        }
    }
// ����readers������ļ��洢
    UpdateReaders();
    if(flag)	printf("success\n");
    else	printf("fail\n");
}