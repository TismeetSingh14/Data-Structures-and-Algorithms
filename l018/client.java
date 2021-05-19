public class client
{
    public static void main(String[] args)
    {
        hashmap<String,Integer> map=new hashmap();
        map.put("abc",100);
        map.put("def",200);
        map.put("ghi",300);
        map.put("jkl",400);
        map.put("mno",500);
        map.put("pqr",600);
        map.put("stu",700);
        map.put("vwx",800);
        map.put("yz1",900);
        map.put("123",300);
        map.put("234",400);
        map.put("345",500);
        map.put("456",600);
        map.put("789",700);
        map.put("890",800);
        map.put("100",900);
        System.out.println(map.keyset());

        System.out.println(map);
    }
}