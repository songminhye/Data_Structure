# HW2

## 문제 : POP, PUSH만을 이용하여 STACK1, STACK2를 합쳐라 


![image](https://user-images.githubusercontent.com/31590051/48851316-14b1dc00-edee-11e8-8777-aa607fafcbff.png)


### [해결방안(간략)]

    stack 1 (0 1 2 3 4) 과 stack 2 (5 6 7 8 9) 를 먼저 만든다.
    
    stack 1 과 stack 2 를 pop, push할 stack 3, stack 4를 만든다. 
    
    stack 3 (4 3 2 1 0) stack 4 (9 8 7 6 5)
    
    결과를 집어넣을 stack5를 만든다.
    
    stack 5에 stack 3, stack 4순서로 하나씩 pop push한다. 

### [코드설명 (자세히)]

    1. stack이 필요하니 먼저 stack 과 stack_node의 struct를 생성한다.
    
    2. stack을 여러 개 생성해야하기 때문에 stack생성 코드를 만든다. 
    
    3. pop, push를 사용해야하기 때문에 pop, push코드 또한 짠다. 
    
    4. 문제에서 stack1과 stack2를 번갈아가며 합쳤기 때문에 순서에 맞게 합치기 위해
      stack1의 순서를 뒤집은 stack3, stack2의 순서를 뒤집은 stack4를 생성한다. 
      (pop은 top만 할 수 있기 때문이다.)
      
    5. stack3를 만들기 위해 stack1를 pop한 것을 바로 stack3에 push한다.
      stack4를 만들기 위해 stack2를 pop한 것을 바로 stack4에 push한다. 
      (1,2의 맨 위에 있는 data가 3,4의 맨 밑으로 간다.)
      
    6. 생성된 stack3과 stack4를 stack3을 먼저 stack5에 pop, push하고 
      stack4를 바로 다음에 pop, push하면서 반복한다. 
      
    7. push가 끝나면 원하는 순서의 stack이 완성된다. 


