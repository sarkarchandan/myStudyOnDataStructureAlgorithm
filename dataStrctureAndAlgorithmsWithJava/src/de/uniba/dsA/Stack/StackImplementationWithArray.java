package de.uniba.dsA.Stack;

/**
 * Stack Implementation with Array
 * Created by chandan on 09.09.16.
 */
public class StackImplementationWithArray {


    private static int[] arrayStack = new int[10];
    private static int stackIndex = -1;

    /**
     * Push method for Stack
     * @param newInteger
     */
    public static void pushtoStack(int newInteger){

        System.out.println("Push method has been called");
        if(stackIndex<9){

            arrayStack[stackIndex+1] = newInteger;
            stackIndex++;
        }else{
            System.out.println("Stack Overflow");
        }
        System.out.println("Current Elements of the Stack are:::::");
        dislayStack();
    }

    /**
     * Pop method for Stack
     * @return
     */
    public static void popFromStack(){
        System.out.println("Pop method has been called");
        int popElement=0;

        try {
            if (stackIndex >= -1) {
                popElement = arrayStack[stackIndex];
                stackIndex--;
            } else {
                System.out.println("Stack Underflow");
            }
            System.out.println("Popped element is: " + popElement);
        }catch (ArrayIndexOutOfBoundsException e){
            System.out.print("Stack Underflow");
        }
        System.out.println("Current Elements of the Stack are:::::");
        dislayStack();
    }

    /**
     * Return the size of the stack at any given point
     * @return
     */
    public static void getSizeOfStack(){
        System.out.println("Size method has been called");

        System.out.println("Current Size of the Stack is: "+ (stackIndex+1));
    }

    /**
     * Indicates if the stack is empty
     * @return
     */
    public static void isEmpty(){

        System.out.println("isEmpty method has been called");
        if(stackIndex==-1)
            System.out.println("Is the Stack Empty: "+true);
        else
            System.out.println("Is the Stack Empty: "+false);
    }


    /**
     * Returns the top/most recently inserted element of the stack
     * @return
     */
    public static void getTopOfTheStack(){

        System.out.println("Top Of the Stack method has been called");
        if(stackIndex>-1) {
            System.out.println("Top Most Element of the Stack Now is: " + (arrayStack[stackIndex]));
        }else {
            System.out.println("Empty Stack");
        }
    }

    /**
     * Display the Stack Array
     */
    public static void dislayStack(){

        for(int counter=0;counter<=stackIndex;counter++){
            System.out.print(arrayStack[counter]);
            System.out.print(",");
        }
        System.out.println("");
    }

}
