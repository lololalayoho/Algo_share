import java.util.*;
public class Main {
    int[] dx = {-1,1,0,0};
    int[] dy = {0,0,-1,1};
    int[][] map;
    ArrayList<String> numbers;
    public void dfs(int x,int y,String word){
        if(word.length()==6){
            if(numbers.contains(word)==false)
                numbers.add(word);
        }
        else{
            for(int i = 0; i<4; i++){
                int nextx = x + dx[i];
                int nexty = y + dy[i];
                if(nextx>=0 && nextx <5 && nexty>=0 && nexty < 5)
                    dfs(nextx,nexty,word + String.valueOf(map[nextx][nexty]));
            }
        }
    }
    public void input(){
        Scanner sc = new Scanner(System.in);
        map = new int[5][5];
        numbers = new ArrayList<>();
        for(int i = 0; i<5; i++) {
            for (int j = 0; j < 5; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        for(int i = 0; i<5; i++){
            for(int j = 0; j<5; j++){
                String word = new String();
                word = String.valueOf(map[i][j]);
                dfs(i,j,word);
            }
        }
    }
    public static void main(String[] args){
       Main main = new Main();
       main.input();
       System.out.println(main.numbers.size());
    }
}
