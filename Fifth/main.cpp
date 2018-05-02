#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

struct Node {
    int nameNode = 0;
    int valTime = 0;
    vector<Node*> pNodes;
};

//get string with times and names Node and init array
void initNameAndTimeNode(Node* pNodes, char* str, int& N) {
    int countNode = 0;
    char* localstr = new char;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ') {
            pNodes[countNode].nameNode = countNode + 1;
            pNodes[countNode].valTime = atoi(localstr);
            countNode++;
            delete[] localstr;
            localstr = new char;
        }
        else localstr[strlen(localstr)] = str[i];
    }
    pNodes[countNode].nameNode = countNode + 1;
    pNodes[countNode].valTime = atoi(localstr);
    
    delete[] localstr;
    localstr = nullptr;
}

// get int(Node number) in char*
int getNumberNode(char* str, char* teleports, int& count) {
    while ((teleports[count] != ' ') && (teleports[count] != '\0')) {
        str[strlen(str)] = teleports[count];
        count++;
    }
    return atoi(str);
}

//add new Node for current Node
//take string (teleports) and get two numbers (current Node and New Node 
//(Rib between current Node and new Node))
void setNodeTeleports(Node* pNodes, char* teleports) {
    char* numberNodestr = new char;
    numberNodestr[0] = 0;
    int count = 0;

    //get Number Nodes
    int numberNode = getNumberNode(numberNodestr, teleports, count);
    delete[] numberNodestr;

    //get Number other Node
    numberNodestr = new char;
    numberNodestr[0] = 0;
    int numberNodeRib = getNumberNode(numberNodestr, teleports, ++count);
    pNodes[numberNode - 1].pNodes.push_back(&pNodes[numberNodeRib - 1]);

    delete[] numberNodestr;
    numberNodestr = nullptr;
}

//come on Grah and search min time
void calculateTime(Node& node, int& countTime, int& minTime, bool& flagStart) {
    if (node.nameNode == 9) {
        if ((minTime > countTime) || (flagStart == true)) {
            minTime = countTime;
            flagStart = false;
        }
        return;
    }
    countTime += node.valTime;
    for (int i = 0; i < node.pNodes.size(); i++) {
        int beforeIn = countTime;
        calculateTime(*(node.pNodes[i]), countTime, minTime, flagStart);
        countTime = beforeIn;
    }
    return;
}

int main() {
    int N = 0, M = 0;
        scanf("%i", &N);
        if (N < 1 || N > 100) {
        cout << "Error! Incorrect enter: N must be  >= 1 and <= 100" << endl;
        return 0;
    }
    //declare N nodes
    Node* pNodes = new Node[N];

    //get time for each nodes
    char* str = new char;
    scanf(" %[^\n]", str);
    
    //set Name and Time for each nodes
    initNameAndTimeNode(pNodes, str, N);

    //get count teleport
    scanf("%i", &M);
    //set teleport for each nodes
    char* teleportsString;
    for (int i = 0; i < M; i++) {
        teleportsString = new char;
        scanf(" %[^\n]", teleportsString);
        setNodeTeleports(pNodes, teleportsString);
        delete[] teleportsString;
    }

    int count = 0, result = 0;
    bool flagStart = true;
    calculateTime(pNodes[0], count, result, flagStart);
    if (flagStart == true)
        cout << "Result = " << -1 << endl;
    else
        cout << "Result = " << result << endl;

    //clear memory
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < pNodes[i].pNodes.size(); j++) {
            pNodes[i].pNodes[j] = nullptr;
        }
    }
    delete[] pNodes;
    pNodes = nullptr;
    delete[] str;
    str = nullptr;
    teleportsString = nullptr;
    return 0;
}