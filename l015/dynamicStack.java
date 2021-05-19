public class dynamicStack extends stack {

    public dynamicStack() {
        super();
    }

    public dynamicStack(int size) {
        super(size);
    }

    public dynamicStack(int[] arr) {
        super(arr);
    }

    @Override
    public void push(int val) {
        
        if(size() == maxSize()) {
            
            int[] temp = new int[size()];

            for(int i=temp.length - 1;i>=0;i--) {
                temp[i] = pop();
            }

            resize(2*temp.length);

            for(int ele:temp) {
                push_(ele);
            }
        } 

        super.push(val);
    }
}
