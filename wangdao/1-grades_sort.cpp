#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*
* 对于非基本数据类型的排序：
* 1. 可以通过构造 cmp 比较函数，作为 sort 函数的第三个参数确定排序规则，当返回 true 时 i 排在 j 前面
* 2. 可以通过对 “ < ” 运算符重载实现
*/

class grade_entry
{
public:
    string name;
    unsigned int grade;
    unsigned int age;
    bool operator<(const grade_entry &j) const
    {
        // 按照成绩一级排序
        if (this->grade != j.grade)
            return this->grade < j.grade;
        // 按照姓名字典序排序
        int name_compare = this->name.compare(j.name);
        if (name_compare != 0)
            return name_compare ? false : true;
        // 按照年龄排序
        return this->age < j.age;
    }
};

bool cmp(grade_entry i, grade_entry j)
{
    // 按照成绩一级排序
    if (i.grade != j.grade)
        return i.grade < j.grade;
    // 按照姓名字典序排序
    int name_compare = i.name.compare(j.name);
    if (name_compare != 0)
        return name_compare ? false : true;
    // 按照年龄排序
    return i.age < j.age;
}

int main(int argc, char const *argv[])
{
    int n;
    grade_entry grades[1000];

    while (cin >> n)
    {
        // 读入数据
        for (int i = 0; i < n; i++)
            cin >> grades[i].name >> grades[i].age >> grades[i].grade;
        // 排序
        sort(grades, grades + n);
        // 输出结果
        for (int i = 0; i < n; i++)
            cout << grades[i].name << ' ' << grades[i].age << ' ' << grades[i].grade << endl;
    }

    return 0;
}

/* 测试用例
3
abc 20 99
bcd 19 97
bed 20 97

预期结果：
bcd 19 97
bed 20 97
abc 20 99
*/
