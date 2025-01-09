#include <iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int* S;
}

void create(struct Stack *st){
    cout << "Enter size of stack";
    cin >> st->size;
    st->top = -1;
    st->S = new int[st->size];

    int peek(Struct st, int pos){
        int i=-1;
        if(st.top-pos+1 < 0){
            cout << "Invalid position";
        } else {
            i = st.S[st.top-pos+1];
        }
    }

    int isEmpty(struct Stack st){
        if(st.top == -1){
            return 1;
        }
        return 0;
    }

    int isFull(struct Stack st){
        return st.top == st.size-1;
    }

    int stackTop(struct Stack st){
        if(!isEmpty(st)){
            return st.S[st.top];
        }
        return -1;
    }

    void push(struct Stack *st, int x){
        if(st->top == st->size-1){
            cout << "Stack overflow";
        } else {
            st->top++;
            st->S[st->top] = x;
        }
    }

    int pop(struct Stack *st){
        int x = -1;
        if(st->top == -1){
            cout << "Stack underflow";
        } else {
            x = st->S[st->top];
            st->top--;
        }
        return x;
    }

    int main(){
        struct Stack st;
        create(&st);

        push(&st, 10);
        push(&st, 20);
        push(&st, 30);
        push(&st, 40);

        cout << pop(&st) << endl;
        return 0;
}