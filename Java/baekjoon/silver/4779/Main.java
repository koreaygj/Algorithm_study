import java.io.*;
 class Main{
     static int N;
     static char Contor[];
    public static void main(String args[])throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str;
        while((str = br.readLine()) != null){
            N = Integer.parseInt(str);
            int input = (int) Math.pow(3, N);
            Contor = new char[input];
            for(int i = 0; i < input; i++)
                Contor[i] = '-';
            dfs(0, input);
            for(int i = 0; i < input; i++)
                bw.write(Contor[i]);
            bw.write("\n");
            bw.flush();
        }
        br.close();
        bw.close();
    }
    static void dfs(int st, int length){
        if(length < 3)
            return;
        int left_end = st + (length / 3);
        int right_st = st + (length / 3) * 2;
        for(int i = left_end; i < right_st; i++)
            Contor[i] = ' ';
        dfs(st, length / 3);
        dfs(right_st, length / 3);
    }
 }