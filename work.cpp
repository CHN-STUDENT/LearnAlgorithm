#include <iostream>
using namespace std;

typedef struct DataBase
{
    string job_name;
    string answer;
}DataBase;

typedef struct Quesion
{
    unsigned int question_num;
    string quesion_name;
    string *quesion_answer;
    string user_input;
}Quesion;

typedef struct Ask_Question
{
	Quesion Ask_Questions[5];
}Ask_Question;

int main()
{
    Ask_Question ask;
    ask.Ask_Questions[1].quesion_name="请输入您有的证照";
    ask.Ask_Questions[1].quesion_answer=
    return 0;
}

