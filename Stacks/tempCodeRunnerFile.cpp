string prifixToPostfix(string a)
{
    struct Node *Head = NULL;
    string result = "";
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
        {
            int x = precedence(a[i]);
            if (Head == NULL or Head->pre < x)
            {
                cout << "1" << endl;
                push(Head, a[i], precedenceStack(a[i]));
                continue;
            }
            while (Head != NULL && Head->pre >= x)
            {
                cout << "2" << endl;
                result = result + Pop(Head);
            }
            push(Head, a[i], precedenceStack(a[i]));
        }
        else if( a[i] == '('){
            push(Head,a[i],precedence(a[i]));
        }
        else if(a[i] == ')'){
            while(Head->data!='('){
                result +=Pop(Head);
            }
            Pop(Head);
        }
        else
        {
            result += a[i];
        }
    }
    while (!isEmpty(Head))
    {
        result += Pop(Head);
    }
    cout << endl;
    return result;
}