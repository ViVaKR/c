#include "headers/main.h"

/// @brief 메인함수
/// @param argc 전달된 정보의 갯수
/// @param argv 전달된 실질 데이터 배열
/// $0 = 프로그램경로, $1 = 첫번째...
/// @return
int main(int argc, char *argv[])
{
    if (argc > 0) {// 전달받은 인수 확인
        for (int i = 0; i < argc; i++) {
            printf("argv[%d] = %s\n", i, argv[i]);
        }
    }

    // 로그 & 파일처리
    time_t rawtime;
    time(&rawtime);
    struct tm *info;
    info = localtime(&rawtime);
    char str[100];
    sprintf(str, "%s", asctime(info));
    Files(false, str);
    Files(true, NULL);

    // 메뉴선택
    long choice;
    char *p;
    if (argc > 1) {
        choice = strtol(argv[1], &p, 10);
        Exec(choice);
    } else {
        do {
            // system("read");
            PrintMenu();
            //-------------------------------------------//
            fflush(stdin);// Clear Buffer
            printf("(번호) >>> ");// 프롬프트 (Prompt)
            scanf("%ld", &choice);// 입력받기 (User Input by int)
            ScreenClear();

            Exec(choice);
        } while (choice != 100);
    }
    // ScreenClear();

    return 0;
    //   exit(EXIT_SUCCESS);
}

void PrintMenu()
{
    printf("\n");
    printf("************************************\n");
    printf("***** 실행할 메뉴를 선택하세요 *****\n");
    printf("************************************\n");
    printf("\n");
    printf("(%03d) 재시작 (ReStart)\n", 0);
    printf("(%03d) Printf\n", 1);
    printf("(%03d) Variable\n", 2);
    printf("(%03d) DataType\n", 3);
    printf("(%03d) ArithmeticOperators\n", 4);
    printf("(%03d) Scanf\n", 5);
    printf("(%03d) Math\n", 6);
    printf("(%03d) Operator\n", 7);
    printf("(%03d) For Loop\n", 8);
    printf("(%03d) While Loop\n", 9);
    printf("(%03d) Do While Loop\n", 10);
    printf("(%03d) Jisikin\n", 11);
    printf("(%03d) Function\n", 12);
    printf("(%03d) Array\n", 13);
    printf("(%03d) Array2D\n", 14);
    printf("(%03d) Recursion\n", 15);
    printf("(%03d) DataStruct\n", 16);
    printf("(%03d) ArrayPoint\n", 17);
    printf("(%03d) CopyMemory\n", 18);
    printf("(%03d) MallocMemset\n", 19);
    printf("(%03d) Pointer (Integer)\n", 20);
    printf("(%03d) Pointer Array\n", 21);
    printf("(%03d) CharArrayPointer\n", 22);

    printf("(%03d) CallByValue\n", 30);
    printf("(%03d) CallByPointer\n", 31);
    
    printf("(%03d) 종료 (Exit)\n", 100);
}

void Exec(int choice)
{
    switch (choice) {
        case 0: {
            execl("/bin/sh", "sh", "/Users/vivabm/GitProjects/C/run.sh", (char *)NULL);

            // exit(42);
        } break;
        case 1: Printf(); break;
        case 2: Variable(); break;
        case 3: DataType(); break;
        case 4: ArithmeticOperators(); break;
        case 5: Scanf(); break;
        case 6: Math(); break;
        case 7: Operator(); break;
        case 8: ForLoop(); break;
        case 9: WhileLoop(); break;
        case 10: DoWhileLoop(); break;
        case 11: Jisikin(); break;
        case 12: Function(); break;
        case 13: Array(); break;
        case 14: Array2D(); break;
        case 15: Recursion(); break;
        case 16: DataStruct(); break;
        case 17: ArrayPointer(); break;
        case 18: CopyMemory(); break;
        case 19: MallocMemset(); break;
        case 20: PointerInt(); break;
        case 21: PointerArray(); break;
        case 22: CharArrayPointer(); break;
        case 30: CallByValue(); break;
        case 31: CallByPointer(); break;
        case 100: {

        } break;
    }

    printf("\n\n==> ( Press Enter View Menus ) <==\n");
}
