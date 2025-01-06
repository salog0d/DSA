#include <iostream?
using namespace std;

struct term
{
    int coeff;
    int exp;
};

struct poly
{
    int n;
    struct term *terms;
};

void create(struct poly *p)
{
    cout << "Enter number of terms: ";
    cin >> p->n;
    p->terms = new term[p->n];
    cout << "Enter polynomial terms:" << endl;
    for (int i = 0; i < p->n; i++)
    {
        cin >> p->terms[i].coeff >> p->terms[i].exp;
    }
}

void display(struct poly p)
{
    cout << "Polynomial: ";
    for (int i = 0; i < p.n; i++)
    {
        cout << p.terms[i].coeff << "x^" << p.terms[i].exp;
        if (i != p.n - 1)
        {
            cout << " + ";
        }
    }
    cout << endl;
}

struct poly *add(struct poly *p1, struct poly *p2)
{
    int i = 0, j = 0, k = 0;
    struct poly *sum = new poly;
    sum->terms = new term[p1->n + p2->n];
    while (i < p1->n && j < p2->n)
    {
        if (p1->terms[i].exp > p2->terms[j].exp)
        {
            sum->terms[k++] = p1->terms[i++];
        }
        else if (p1->terms[i].exp < p2->terms[j].exp)
        {
            sum->terms[k++] = p2->terms[j++];
        }
        else
        {
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }
    for (; i < p1->n; i++)
    {
        sum->terms[k++] = p1->terms[i];
    }
    for (; j < p2->n; j++)
    {
        sum->terms[k++] = p2->terms[j];
    }
    sum->n = k;
    return sum;
}

int main()
{
    struct poly p1, p2, *sum;
    create(&p1);
    create(&p2);
    sum = add(&p1, &p2);
    display(p1);
    display(p2);
    display(*sum);
    return 0;
}

