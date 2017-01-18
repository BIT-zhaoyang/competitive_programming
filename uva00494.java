import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine()){
            int ans = 0;
            String line = sc.nextLine().trim();
            String[] words = line.split("[^a-zA-Z]+");
            for(String ele : words)
                if(ele.length() > 0)
                    ++ans;
            System.out.println(ans);
        }
    }
}
