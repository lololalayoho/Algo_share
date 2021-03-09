import java.util.*;
public class Main {
    int[] dx = {-1,1,0,0};
    int[] dy = {0,0,-1,1};
    int[][] map;
    int answer;
    int[][] visit;
    int N; int M;int zero_cnt;int one_cnt;
    class position{
        int x;
        int y;
        int value;
    }
    Queue<position> queue;
    public void bfs(){
        while(!queue.isEmpty()){
            int px = queue.peek().x;
            int py = queue.peek().y;
            int pvalue = queue.peek().value;
            queue.poll();
            one_cnt = one_cnt + 1;
            if(pvalue > answer)
                answer = pvalue;
            for(int i = 0; i<4; i++){
                int nextx = px + dx[i];
                int nexty = py + dy[i];
                if(nextx>=0 && nextx <N && nexty>=0 && nexty<M){
                    if(visit[nextx][nexty]==0 && map[nextx][nexty] == 0){
                        visit[nextx][nexty] = pvalue+1;
                        position p = new position();
                        p.x = nextx; p.y = nexty; p.value =pvalue+1;
                        queue.offer(p);
                    }
                }
            }
        }
        if(one_cnt!=zero_cnt)
            answer = -1;
    }
    public void input(){
        Scanner sc = new Scanner(System.in);
        M = sc.nextInt(); N = sc.nextInt();
        queue = new LinkedList<>();
        answer = 0;zero_cnt = 0;one_cnt = 0;
        map = new int[N][M];
        visit = new int[N][M];
        for(int i = 0; i<N; i++) {
            for (int j = 0; j < M; j++) {
                map[i][j] = sc.nextInt();
                visit[i][j] = 0;
                if (map[i][j] == 1) {
                    position p = new position();
                    p.x = i;
                    p.y = j;
                    p.value = 0;
                    visit[p.x][p.y] = 1;
                    queue.offer(p);
                }
                if(map[i][j] != -1){
                    zero_cnt = zero_cnt + 1;
                }
            }
        }
    }
    public static void main(String[] args){
       Main main = new Main();
       main.input();
       main.bfs();
       System.out.println(main.answer);
    }
}