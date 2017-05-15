import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine()){
            String input = sc.nextLine();
            if(input.equals("e/o/i"))   break;

            String[] lines = input.split("/");
            boolean ok1 = true, ok2 = true, ok3 = true;

            if(lines[0].replaceAll("[^aeiouy]+", " ").trim().split(" ").length != 5) ok1 = false;
            if(lines[1].replaceAll("[^aeiouy]+", " ").trim().split(" ").length != 7) ok2 = false;
            if(lines[2].replaceAll("[^aeiouy]+", " ").trim().split(" ").length != 5) ok3 = false;

            if(!ok1)    System.out.println("1");
            else if(!ok2)    System.out.println("2");
            else if(!ok3)    System.out.println("3");
            else    System.out.println("Y");
        }
    }
}
