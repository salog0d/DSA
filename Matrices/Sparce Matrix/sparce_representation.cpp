#include <iostream>
using namespace std;

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    Element *ele;
};

void create(Sparse *s)
{
    cout << "Enter dimensions: ";
    cin >> s->m >> s->n;
    cout << "Enter number of non-zero elements: ";
    cin >> s->num;
    s->ele = new Element[s->num];
    cout << "Enter non-zero elements:" << endl;
    for (int i = 0; i < s->num; i++)
    {
        cin >> s->ele[i].i >> s->ele[i].j >> s->ele[i].x;
    }
}

void display(Sparse s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (i == s.ele[k].i && j == s.ele[k].j)
            {
                cout << s.ele[k++].x << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

Sparse *add(Sparse *s1, Sparse *s2)
{
    if (s1->m != s2->m || s1->n != s2->n)
    {
        return nullptr;
    }
    Sparse *sum = new Sparse;
    sum->m = s1->m;
    sum->n = s1->n;
    sum->ele = new Element[s1->num + s2->num];
    int i = 0, j = 0, k = 0;
    while (i < s1->num && j < s2->num)
    {
        if (s1->ele[i].i < s2->ele[j].i)
        {
            sum->ele[k++] = s1->ele[i++];
        }
        else if (s1->ele[i].i > s2->ele[j].i)
        {
            sum->ele[k++] = s2->ele[j++];
        }
        else
        {
            if (s1->ele[i].j < s2->ele[j].j)
            {
                sum->ele[k++] = s1->ele[i++];
            }
            else if (s1->ele[i].j > s2->ele[j].j)
            {
                sum->ele[k++] = s2->ele[j++];
            }
            else
            {
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
    }
    for (; i < s1->num; i++)
    {
        sum->ele[k++] = s1->ele[i];
    }
    for (; j < s2->num; j++)
    {
        sum->ele[k++] = s2->ele[j];
    }
    sum->num = k;
    return sum;
}

int main()
{
    Sparse s1, s2;
    create(&s1);
    create(&s2);
    Sparse *sum = add(&s1, &s2);
    if (sum == nullptr)
    {
        cout << "Addition not possible." << endl;
    }
    else
    {
        cout << "First Matrix:" << endl;
        display(s1);
        cout << "Second Matrix:" << endl;
        display(s2);
        cout << "Sum Matrix:" << endl;
        display(*sum);
    }
    return 0;
}