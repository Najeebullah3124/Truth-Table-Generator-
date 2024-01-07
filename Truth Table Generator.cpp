
#include<iostream>
#include<string>
#include<math.h>
#include<conio.h>
#include<iomanip>

using namespace std;

struct variable {
    string str = "";
    int* arr = nullptr;
};

class Node {
public:
    char data;
    Node* next;
    Node(char n) {
        data = n;
        next = nullptr;
    }
};

class Stack {
public:
    Node* top;

    Stack() {
        top = NULL;
    }

    ~Stack() {
        makenull();
    }

    void push(char n) {
        Node* newnode = new Node(n);
        newnode->next = top;
        top = newnode;
    }

    char pop() {
        if (isempty())
        {
            cout << endl << "STACK UNDERFLOW 1" << endl;
            return '0';
        }
        else {
            Node* current = top;
            char v = top->data;
            top = top->next;
            delete current;
            return v;
        }
    }

    bool isempty() {
        return (top == NULL);
    }

    void makenull() {
        while (!isempty()) {
            pop();
        }
    }

    char getTop() {
        if (!isempty()) {
            return top->data;
        }
        return '\0';
    }

};




struct StringNode {
    string str = "";
    StringNode* next = nullptr;
};

class StringStack {
private:
    StringNode* top;
public:
    StringStack() {
        top = nullptr;
    }
    bool isEmpty() {
        if (top == nullptr) {
            return true;
        }
        return false;
    }
    void Push(string str) {
        StringNode* newNode = new StringNode;
        newNode->str = str;
        newNode->next = top;
        top = newNode;
    }
    string Pop() {
        string str = top->str;
        StringNode* temp = top;
        top = top->next;
        delete temp;
        return str;
    }
};


/*---------------------|Operations|---------------------|*/

void AND_operation(string left, string right, variable* vari, int totalElements, int totalVariables, int totalOperations) {
    int newSpace = -1;
    int leftIndex = 0;
    int rightIndex = 0;
    string newStr = left + "." + right;
    for (int i = 0; i < totalOperations + totalVariables; i++) {
        if (newStr == vari[i].str) {
            return;
        }
        else if (vari[i].str == "" && newSpace == -1) {
            newSpace = i;
        }
        else if (vari[i].str == left) {
            leftIndex = i;
        }
        else if (vari[i].str == right) {
            rightIndex = i;
        }
    }

    vari[newSpace].str = newStr;
    for (int i = 0; i < totalElements; i++) {
        vari[newSpace].arr[i] = vari[leftIndex].arr[i] & vari[rightIndex].arr[i];
    }
}

void OR_operation(string left, string right, variable* vari, int totalElements, int totalVariables, int totalOperations) {
    int newSpace = -1;
    int leftIndex = 0;
    int rightIndex = 0;
    string newStr = left + "+" + right;
    for (int i = 0; i < totalOperations + totalVariables; i++) {
        if (newStr == vari[i].str) {
            return;
        }
        else if (vari[i].str == "" && newSpace == -1) {
            newSpace = i;
        }
        else if (vari[i].str == left) {
            leftIndex = i;
        }
        else if (vari[i].str == right) {
            rightIndex = i;
        }
    }

    vari[newSpace].str = newStr;
    for (int i = 0; i < totalElements; i++) {
        vari[newSpace].arr[i] = vari[leftIndex].arr[i] | vari[rightIndex].arr[i];
    }
}

void NOT_operation(string str, variable* vari, int totalElements, int totalVariables, int totalOperations) {
    int newSpace = -1;
    int left = -1;
    string newStr = str + "'";
    for (int i = 0; i < totalOperations + totalVariables; i++) {
        if (newStr == vari[i].str) {
            return;
        }
        else if (vari[i].str == "" && newSpace == -1) {
            newSpace = i;
        }
        else if (vari[i].str == str) {
            left = i;
        }
    }

    vari[newSpace].str = newStr;
    for (int i = 0; i < totalElements; i++) {
        vari[newSpace].arr[i] = ((vari[left].arr[i] + 1) % 2);
    }
}

void Implies_operation(string left, string right, variable* vari, int totalElements, int totalVariables, int totalOperations) {
    int newSpace = -1;
    int leftIndex = 0;
    int rightIndex = 0;
    string newStr = left + "->" + right;
    for (int i = 0; i < totalOperations + totalVariables; i++) {
        if (newStr == vari[i].str) {
            return;
        }
        else if (vari[i].str == "" && newSpace == -1) {
            newSpace = i;
        }
        else if (vari[i].str == left) {
            leftIndex = i;
        }
        else if (vari[i].str == right) {
            rightIndex = i;
        }
    }

    vari[newSpace].str = newStr;
    for (int i = 0; i < totalElements; i++) {
        if (vari[leftIndex].arr[i] == 1 && vari[rightIndex].arr[i] == 0) {
            vari[newSpace].arr[i] = 0;
        }
        else {
            vari[newSpace].arr[i] = 1;
        }
    }
}

void XOR_operation(string left, string right, variable* vari, int totalElements, int totalVariables, int totalOperations) {
    int newSpace = -1;
    int leftIndex = 0;
    int rightIndex = 0;
    string newStr = left + "#" + right;
    for (int i = 0; i < totalOperations + totalVariables; i++) {
        if (newStr == vari[i].str) {
            return;
        }
        else if (vari[i].str == "" && newSpace == -1) {
            newSpace = i;
        }
        else if (vari[i].str == left) {
            leftIndex = i;
        }
        else if (vari[i].str == right) {
            rightIndex = i;
        }
    }

    vari[newSpace].str = newStr;
    for (int i = 0; i < totalElements; i++) {
        if (vari[leftIndex].arr[i] != vari[rightIndex].arr[i]) {
            vari[newSpace].arr[i] = 1;
        }
        else {
            vari[newSpace].arr[i] = 0;
        }
    }
}

void BIconditional_operation(string left, string right, variable* vari, int totalElements, int totalVariables, int totalOperations) {
    int newSpace = -1;
    int leftIndex = 0;
    int rightIndex = 0;
    string newStr = left + "<->" + right;
    for (int i = 0; i < totalOperations + totalVariables; i++) {
        if (newStr == vari[i].str) {
            return;
        }
        else if (vari[i].str == "" && newSpace == -1) {
            newSpace = i;
        }
        else if (vari[i].str == left) {
            leftIndex = i;
        }
        else if (vari[i].str == right) {
            rightIndex = i;
        }
    }

    vari[newSpace].str = newStr;
    for (int i = 0; i < totalElements; i++) {
        if (vari[leftIndex].arr[i] == vari[rightIndex].arr[i]) {
            vari[newSpace].arr[i] = 1;
        }
        else {
            vari[newSpace].arr[i] = 0;
        }
    }
}

/*---------------------|Operations|---------------------|*/


/*---------------------|Global Functions|---------------------|*/

int getPrecedence(char op) {
    if (op == '\'') {
        return 5; // NOT has the highest precedence
    }
    else if (op == '#') {
        return 4; // XOR
    }
    else if (op == '.') {
        return 3; // AND
    }
    else if (op == '+') {
        return 2; // OR
    }
    else if (op == '~') {
        return 1; // IMPLIES
    }
    else if (op == '@') {
        return 0; // BICONDITIONAL
    }
    return -1; // Default for other characters
}

bool isbalanced(string infix)
{
    Stack S1;
    for (char a : infix)  //for each
    {
        if (a == '(' || a == '[' || a == '{')
        {
            S1.push(a);
        }
        else if (a == ')' || a == ']' || a == '}')
        {
            if (S1.isempty()) { return false; }
            char topChar = S1.getTop();
            S1.pop();
            if ((a == ')' && topChar != '(') ||
                (a == ']' && topChar != '[') ||
                (a == '}' && topChar != '{')) {
                return false;
            }
        }

    }
    return S1.isempty();
}

string infixToPostfix(string infixExpression) {
    string postfixExpression = "";
    Stack S1;

    int c = 0;
    for (int i = 0; i < infixExpression.length(); i++) {

        if ((infixExpression[i] >= 'a' && infixExpression[i] <= 'z') ||
            (infixExpression[i] >= 'A' && infixExpression[i] <= 'Z')) {
            postfixExpression = postfixExpression + infixExpression[i];  // Operand
        }
        else if (infixExpression[i] == '(' || infixExpression[i] == '[' || infixExpression[i] == '{') {
            S1.push(infixExpression[i]);
        }
        else if (infixExpression[i] == ')' || infixExpression[i] == ']' || infixExpression[i] == '}') {
            while (!S1.isempty() && S1.getTop() != '(' && S1.getTop() != '[' && S1.getTop() != '{') {
                postfixExpression += S1.pop();
            }
            S1.pop();
        }
        else if (infixExpression[i] == '\'') {
            postfixExpression += infixExpression[i];
        }
        //., +, <->, ->, '
        else if (getPrecedence(infixExpression[i]) < getPrecedence(S1.getTop())) {
            while (getPrecedence(infixExpression[i]) < getPrecedence(S1.getTop())) {
                postfixExpression += S1.pop();
            }
            if (infixExpression[i] == '<' && infixExpression[i + 1] == '-' && infixExpression[i + 2] == '>') {
                //<->
                S1.push('@');
                i += 2;
            }
            else if (infixExpression[i] == '-' && infixExpression[i + 1] == '>') {
                //->
                S1.push('~');
                i++;
            }
            else {
                S1.push(infixExpression[i]);
            }
        }
        else {
            if (infixExpression[i] == '<' && infixExpression[i + 1] == '-' && infixExpression[i + 2] == '>') {
                S1.push('@');
                i += 2;
            }
            else if (infixExpression[i] == '-' && infixExpression[i + 1] == '>') {
                S1.push('~');
                i++;
            }
            else {
                S1.push(infixExpression[i]);
            }
        }
    }

    while (!S1.isempty()) {
        postfixExpression += S1.pop();
    }
    return postfixExpression;
}

int count_variable(string infix)
{
    int count = 0;
    char arr[52] = {};
    for (int c = 0; infix[c] != '\0'; c++)
    {
        char ch = infix[c];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            bool ok = false;
            for (int j = 0; arr[j] != '\0'; j++)
            {
                if (ch == arr[j])
                {
                    ok = true;
                    break;
                }

            }
            if (ok == false)
            {
                arr[count] = ch;
                count++;
            }

        }
    }
    return count;
}

int count_operations(string infix)
{
    int count = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '+' || infix[i] == '.' || infix[i] == 39 || infix[i] == '#')
        {
            count++;
        }
        else if (infix[i] == '<' && infix[i + 1] == '-' && infix[i + 2] == '>')
        {
            count++;
            i += 2;
        }
        else if (infix[i] == '-' && infix[i + 1] == '>')
        {
            count++;
            i++;
        }
    }
    return count;
}

variable* initializeVariables(string str, int totalVariables, int totalElements, int totalOperations) {
    variable* temp = new variable[totalVariables + totalOperations];
    int* power = new int[totalVariables];
    int index = 0;
    int i = 0;
    //Add basic varibles into struct
    char chArr[52] = {};
    int c = 0;

    while (str[i] != '\0') {
        char ch = str[i];

        bool found = false;
        int j = 0;

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            bool ok = false;
            for (int j = 0; chArr[j] != '\0'; j++)
            {
                if (ch == chArr[j])
                {
                    ok = true;
                    break;
                }

            }
            if (ok == false)
            {
                chArr[c] = ch;
                c++;
            }
        }

        i++;
    }

    for (int k = 0; k < c; k++) {
        temp[k].str = chArr[k];
    }


    for (int j = 1; j <= totalVariables; j++) {
        power[j - 1] = pow(2, totalVariables - j);
    }

    for (int j = 0; j < totalVariables + totalOperations; j++) {
        temp[j].arr = new int[totalElements];
        for (int k = 0; k < totalElements; k++) {
            temp[j].arr[k] = -1;
        }
    }

    int insert = 1;
    for (int j = 0; j < totalVariables; j++) {
        for (int k = 0; k < totalElements; k++) {
            if (k % power[j] == 0) { insert = (insert + 1) % 2; }
            temp[j].arr[k] = insert;
        }
    }

    return temp;
}

void calculate(string str, variable* vari, int totalElements, int totalVariables, int totalOperations) {
    int i = 0;

    StringStack s2;

    while (str[i] != '\0') {
        char ch = str[i];
        string tempS = "";
        if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z') {
            tempS = ch;
            s2.Push(tempS);
        }
        else {
            if (ch == '\'') {
                string TOP = s2.Pop();
                NOT_operation(TOP, vari, totalElements, totalVariables, totalOperations);
                TOP += '\'';
                s2.Push(TOP);
            }
            else if (ch == '.') {
                string Right = s2.Pop();
                string Left = s2.Pop();
                AND_operation(Left, Right, vari, totalElements, totalVariables, totalOperations);
                s2.Push(Left + '.' + Right);
            }
            else if (ch == '~') {
                string Right = s2.Pop();
                string Left = s2.Pop();
                Implies_operation(Left, Right, vari, totalElements, totalVariables, totalOperations);
                s2.Push(Left + "->" + Right);
            }
            else if (ch == '@') {
                string Right = s2.Pop();
                string Left = s2.Pop();
                BIconditional_operation(Left, Right, vari, totalElements, totalVariables, totalOperations);
                s2.Push(Left + "<->" + Right);
            }
            else if (ch == '+') {
                string Right = s2.Pop();
                string Left = s2.Pop();
                OR_operation(Left, Right, vari, totalElements, totalVariables, totalOperations);
                s2.Push(Left + '+' + Right);
            }
            else if (ch == '#') {
                string Right = s2.Pop();
                string Left = s2.Pop();
                XOR_operation(Left, Right, vari, totalElements, totalVariables, totalOperations);
                s2.Push(Left + '#' + Right);
            }
        }
        i++;
    }
}

/*---------------------|Global Functions|---------------------|*/

int main() {
    string infixExp, postfixExp;
    string defaultExp = "A+B#C";
    char asciiArt[] = R"(
      _____           _   _       _____     _     _         ____                           _             
     |_   _| __ _   _| |_| |__   |_   _|_ _| |__ | | ___   / ___| ___ _ __   ___ _ __ __ _| |_ ___  _ __ 
       | || '__| | | | __| '_ \    | |/ _` | '_ \| |/ _ \ | |  _ / _ \ '_ \ / _ \ '__/ _` | __/ _ \| '__|
       | || |  | |_| | |_| | | |   | | (_| | |_) | |  __/ | |_| |  __/ | | |  __/ | | (_| | || (_) | |   
       |_||_|   \__,_|\__|_| |_|   |_|\__,_|_.__/|_|\___|  \____|\___|_| |_|\___|_|  \__,_|\__\___/|_|   
)";

    cout << asciiArt;
    cout << "Enter an Expression\n";
    cout << "--------------------------------------------------\n";
    cout << "Use '+' for OR\t\t| Use '.' for AND\n";
    cout << "Use ''' for NOT\t\t| Use '#' for XOR\n";
    cout << "Use '->' for Implies\t| Use '<->' for BiCondi\n";
    cout << "--------------------------------------------------\n";
    cout << ">> "; getline(cin, infixExp);
    if (infixExp == "") {
        infixExp = defaultExp;
        cout << "Empty expression detected! Adding default expression.\n";
        cout << ">> " << defaultExp << endl;
    }
    else {
        if (!isbalanced(infixExp)) {
            cout << "Brackets Imbalance Detected! Terminating the Program!" << endl;
            return 0;
        }
    }

    int TotalVariables = count_variable(infixExp);
    int TotalOperations = count_operations(infixExp);
    int TotalElements = pow(2, TotalVariables);

    postfixExp = infixToPostfix(infixExp);

    variable* AllOperationsList = initializeVariables(infixExp, TotalVariables, TotalElements, TotalOperations);

    calculate(postfixExp, AllOperationsList, TotalElements, TotalVariables, TotalOperations);

    for (int i = 0; i < TotalVariables + TotalOperations; i++) {
        int size = AllOperationsList[i].str.length();
        cout << setw(size) << AllOperationsList[i].str << setw(4) << " ";
    }
    cout << endl;

    for (int i = 0; i < TotalElements; i++) {
        for (int j = 0; j < TotalVariables + TotalOperations; j++) {
            int size = AllOperationsList[j].str.length();
            if (AllOperationsList[j].arr[i] == 1) {
                cout << setw(size) << "T" << setw(4) << " ";
            }
            else {
                cout << setw(size) << "F" << setw(4) << " ";
            }
        }
        cout << endl;
    }
    system("pause");
}