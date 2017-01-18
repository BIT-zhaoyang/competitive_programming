import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine()){
            String str = sc.nextLine().trim();
            if(str.equals("*"))  break;
            if(str.matches("[+-]?\\d+(\\.\\d+([eE][-+]?\\d+)?|[eE][-+]?\\d+)")){
                System.out.printf("%s is legal.\n", str);
            } else {
                System.out.printf("%s is illegal.\n", str);
            }
        }
    }
}
