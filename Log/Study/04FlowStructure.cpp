# include <iostream>
using namespace std;

int main(){
    // 4. 程序流程结构
    // 4.1 选择结构
    // 4.1.1. if语句
    // 注意事项, if语句后面不要加分号";"
    int score = 655;
    // cout << "请输入你的成绩: ";
    // cin >> score;
    if (score>500)
    {
        cout<<"一本大学"<<"\n";
        if (score>600&&score<650)
        {
            cout<<"211大学"<<"\n";
        }
        else if (score>650)
        {
            cout<<"985大学"<<"\n";
        }
        
    }
    else if (score<500&&score>300)
    {
        cout<<"二本大学"<<"\n";
    }
    else{
        cout<<"大专院校"<<"\n";
    }
    // 判断三只小猪的体重
    int a, b, c, t;
    a = 200;
    b = 300;
    c = 100;
    // cout << "The weight of pig A: ";
    // cin >> a;
    // cout << "The weight of pig B: ";
    // cin >> b;
    // cout << "The weight of pig C: ";
    // cin >> c;
    t = a;
    if (a>b)
    {
        t = a;
        if (a>c){
            t = a;
            cout << "小猪A最重,重" << t <<"\n";
        }
        else{
            t = c;
            cout << "小猪C最重,重" << t <<"\n";
        }
    }
    else
    {
        t = b;
        if (b>c){
            t = b;
            cout << "小猪B最重,重" << t <<"\n";
        }
        else{
            t = c;
            cout << "小猪C最重,重" << t <<"\n";
        }
    }
    // t = max(max(a,b),c);
    cout << "The heaviest of pig is: " << t <<"\n";
    
    // 4.1.2 三目运算符
    return 0;
}