# HW1

## 문제 : POP, PUSH만을 이용하여 STACK1, STACK2를 합쳐라 

### [해결방안(간략)]

    stack1 (0 1 2 3 4) 과 stack2 (5 6 7 8 9) 를 먼저 만든다. 
    
    stack2를 pop해서 다시 push할 stack3를 만든다 (9 8 7 6 5)
    
    stack3의 값들을 다시 pop해서 stack1 에 push한다. 
    
    (0 1 2 3 4 5 6 7 8 9)
    

### [코드설명 (자세히)]

    1. stack이 필요하니 먼저 stack 과 stack_node의 struct를 생성한다.
    
    2. stack을 여러 개 생성해야하기 때문에 stack생성 코드를 만든다. 
    
    3. pop, push를 사용해야하기 때문에 pop, push코드 또한 짠다. 
    
    4. 문제에서 stack1과 stack2를 한 번에 합쳤기 때문에 순서에 맞게 합치기 위해
      stack2의 순서를 뒤집은 stack3를 생성해야한다. 
      (pop은 top만 할 수 있기 때문에 4다음에 5가 오려면 stack3의 top에 5가 있어야한다.)
      
    5. stack3를 만들기 위해 stack2를 pop한 것을 바로 stack3에 push한다. 
    
    6. 생성된 stack3를 pop한 것을 바로 stack1에 push하면 원하는 결과의 stack이 완성된다.
