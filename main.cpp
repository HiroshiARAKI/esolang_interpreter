/**
 * @brief You can make an Esoteric programming language Interpreter based on Brainf*ck.
 *
 * @author HiroshiARAKI
 * @date 2020.01.05
 * @copyright https://hirlab.net
 * @code https://github.com/HiroshiARAKI/
 * @LICENSE MIT
 *
 * @refitem https://gist.github.com/7shi/527649
 */

#include <iostream>
#include <stack>
#include "orders.h"

#define MEMORY_SIZE 1024


using namespace std;

int main(int argc, char* argv[]) {
    /* memory of array */
    char memory[MEMORY_SIZE];

    /* source code */
    char *source = nullptr;

    /* recurrent pointer */
    unsigned short ptr = 0;

    /* recurrent pointer of the source code */
    int order_ptr = 0;

    /* end of pointer of the source code */
    int order_end = 0;

    /* stack of multi-loop */
    stack<int> loops;


    /* initialize memory */
    memset(memory, 0, sizeof(memory));

    // check command line arguments
    if(argc < 2){
        cout << "Oops! There are no-arguments." << endl;
        return 0;
    }

    /* get filename */
    char *filename = argv[1];
    FILE *fp;

    /* open file */
    if (!(fp = fopen(filename, "rb"))){
        cout << "ERROR: Not found the designated file." << endl;
        return -1;
    }

    /* get code */
    if(fseek(fp, 0, SEEK_END) == 0){
        int size = ftell(fp);
        if(fseek(fp, 0, SEEK_SET) == 0){
            source = new char[size];
            order_end = fread(source, 1, size, fp);
        }
    }
    fclose(fp);

    /* main loop */
    while(order_ptr < order_end){
        /* order switch */
        switch(source[order_ptr]){
            case PTR_INCREMENT:
                ptr++;
                break;
            case PTR_DECREMENT:
                ptr--;
                break;
            case BYTE_INCREMENT:
                (memory[ptr])++;
                break;
            case BYTE_DECREMENT:
                (memory[ptr])--;
                break;
            case OUTPUT:
                putchar(memory[ptr]);
                break;
            case INPUT:
                memory[ptr] = getchar();
                break;
            case LOOP_START:
                loops.push(order_ptr);
                if(memory[ptr] == 0){
                    int depth = 1;
                    while(depth > 0){
                        order_ptr++;
                        if(order_ptr >= order_end){
                            cout << "ERROR: Not found \'" << LOOP_END << "\' ." <<endl;
                            return -1;
                        }
                        switch(source[order_ptr]){
                            case LOOP_START:
                                depth++;
                                break;
                            case LOOP_END:
                                depth--;
                                break;
                        }
                    }
                    loops.pop();
                }
                break;
            case LOOP_END:
                if(loops.empty()){
                    cout << "ERROR: Not found \'" << LOOP_START << "\'." <<endl;
                    return -1;
                }
                order_ptr = loops.top() - 1;
                loops.pop();
                break;

            default: /* characters except the orders are handled as a comment */
                break;
        }
        /* increment the recurrent order pointer */
        order_ptr++;
    }

    delete[] source;

    return 0;
}