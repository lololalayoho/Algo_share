import java.util.*;
class Solution {
    class positioin{
        int x;
        int y;
    }
    public positioin move(char dir){
        positioin p = new positioin();
        if(dir=='U'){
            p.x = -1;p.y = 0;
        }
        else if(dir=='D'){
            p.x = 1; p.y = 0;
        }
        else if(dir=='R'){
            p.x = 0; p.y = 1;
        }
        else if(dir=='L'){
            p.x = 0; p.y = -1;
        }
        return p;
    }
    public int solution(String dirs) {
        int answer = 0;
        List<String> roads = new ArrayList<>();
        positioin pos = new positioin();
        pos.x = 5; pos.y = 5;
        for(int i = 0; i<dirs.length();i++){
            positioin p = new positioin();
            p = move(dirs.charAt(i));
            int nextx = pos.x + p.x;
            int nexty = pos.y + p.y;
            if(nextx>=0 && nextx<11 && nexty>=0 && nexty <11){
                String word1 = String.valueOf(pos.x)+" "+String.valueOf(pos.y)+" "+String.valueOf(nextx)+" "+String.valueOf(nexty);
                String word2 = String.valueOf(nextx)+" "+String.valueOf(nexty)+" "+String.valueOf(pos.x)+" "+String.valueOf(pos.y);
                if(roads.contains(word1)==false && roads.contains(word2)==false){
                    answer = answer + 1;
                    roads.add(word1);
                    roads.add(word2);
                }
                pos.x = nextx; pos.y = nexty;
            }
        }
        return answer;
    }
}