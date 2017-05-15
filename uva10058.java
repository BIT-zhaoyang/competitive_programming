import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine()){
            String line = sc.nextLine();
            boolean valid = processLine(line);
            if(valid)   System.out.println("YES I WILL");
            else    System.out.println("NO I WON'T");
        }
    }

    static private boolean processLine(String line){
        line = line.trim();
        String[] actions = line.split(" , ");
        boolean valid = true;
        for(String ele : actions)
            valid = valid && processAction(ele);
        return valid;
    }

    static private boolean processAction(String action){
        action = action.trim();
        String[] activeList = action.split(" (hate(s)?|love(s)?|know(s)?|like(s)?) ");

        boolean valid = (activeList.length == 2);
        for(String ele : activeList)
            valid = valid && processActiveList(ele);
        return valid;
    }

    static private boolean processActiveList(String activeList){
        activeList = activeList.trim();
        String[] actor = activeList.split(" and ");
        boolean valid = true;
        for(String ele : actor)
            valid = valid && processActor(ele);
        return valid;
    }

    static private boolean processActor(String actor){
        actor = actor.trim();
        boolean valid = actor.matches("(a |the )?(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)");
        return valid;
    }
}
