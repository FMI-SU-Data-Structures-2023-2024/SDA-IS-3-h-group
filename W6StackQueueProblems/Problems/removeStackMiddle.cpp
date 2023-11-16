//#include <iostream>
//#include <stack>
//
//// https://www.geeksforgeeks.org/delete-middle-element-stack/
//int main() {
//    std::stack<int> stack;
//    int n;
//    std::cin >> n;
//    for (int i = 0; i < n; ++i)
//    {
//        int nextElement;
//        std::cin >> nextElement;
//        stack.push(nextElement);
//    }
//
//    std::stack<int> newStack;
//    int counter = 0;
//    while (!stack.empty()) {
//        counter++;
//        newStack.push(stack.top());
//        stack.pop();
//    }
//    int half = counter / 2;
//    while (!newStack.empty()){
//        counter--;
//        if (counter == half) {
//            newStack.pop();
//            continue;
//        }
//        stack.push(newStack.top());
//        newStack.pop();
//    }
//
//    while (!stack.empty()) {
//        std::cout << stack.top();
//        stack.pop();
//    }
//    return 0;
//}