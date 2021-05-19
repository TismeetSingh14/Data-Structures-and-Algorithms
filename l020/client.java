public class client
{
    public static void main(String[] args)
    {
        linkedlist<Integer> ll=new linkedlist<>();
        ll.addfirst(6);
        ll.addfirst(5);
        ll.addfirst(4);
        ll.addfirst(3);
        ll.addfirst(2);
        ll.addfirst(1);
        ll.addfirst(0);
        System.out.println(ll);
    }
}