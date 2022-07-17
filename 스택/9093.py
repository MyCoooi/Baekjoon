testcase = int(input())

output = []
for i in range(0,testcase):
    words = input()
    stack = []
    word = []
    for j in range(len(words)):
        if (words[j] == " "):
            for k in range(len(word)):
                stack.append(word.pop())
            stack.append(" ")
            word = []
        else:
            word.append(words[j])
            
    #stack.append(" ")
    for j in range(len(word)):
        stack.append(word.pop())
    word = []
    
    for j in range(len(stack)):
        output.append(stack[j])
    output.append('\n')

for i in range(len(output)):
    print(output[i], end="")
