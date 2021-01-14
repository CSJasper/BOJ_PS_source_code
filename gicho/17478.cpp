#include <iostream>
#include <string>

#define PASSAGE_LENGTH 100

typedef struct collection
{
    std::string str1;
    std::string str2;
    std::string str3;
    std::string str4;
    std::string str5;
}collection_t;

void print_recursive(int, collection_t str, int size);

int main(void)
{
    std::string intro = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.";
    std::string str2 = "\"재귀함수가 뭔가요?\"";
    std::string str3 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
    std::string str4 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
    std::string str5 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
    std::string str6 = "라고 답변하였지.";
    collection_t str = {str2, str3, str4, str5, str6};
    int size;
    std::cin >> size;
    std::cout << intro << '\n';
    print_recursive(size, str, size);

    return 0;
}

void print_recursive(int depth, collection_t str, int size)
{
    if(depth == size || depth == 1) 
        std::cout << str.str1 << '\n' << str.str2 << '\n' << str.str3 << '\n' << str.str4 << '\n';
    else
    {
        std::string add = "____";
        collection_t tmp = {add + str.str1 , add + str.str2, add + str.str3,
                            add + str.str4, add + str.str5};
        print_recursive(depth - 1, tmp, size);
    }
    std::cout << str.str5 << '\n';
}