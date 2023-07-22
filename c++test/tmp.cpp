#include <iostream>
#include <stack>

struct Move
{
    int n;
    char source, dest, aux;
    // bool recursive_call;
};

void moveDisk(char source, char dest)
{
    std::cout << "Move disk from " << source << " to " << dest << std::endl;
}

void iterativeHanoi(int numDiscs, char source, char aux, char dest)
{
    std::stack<Move> callStack;
    callStack.push({numDiscs, source, dest, aux});

    while (!callStack.empty())
    {
        Move currentMove = callStack.top();
        callStack.pop();

        int n = currentMove.n;
        char src = currentMove.source;
        char dst = currentMove.dest;
        char aux = currentMove.aux;

        if (n == 1)
        {
            moveDisk(src, dst);
        }
        else
        {
            callStack.push({n - 1, src, aux, dst});
            callStack.push({1, src, dst, aux});
            callStack.push({n - 1, aux, dst, src});
        }
    }
}

int main()
{
    int numDiscs = 3;
    char source = 'A', aux = 'B', dest = 'C';

    iterativeHanoi(numDiscs, source, aux, dest);

    return 0;
}
