import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Main {
	//board[][]
	static final char EMPTY = ' ';
	static final char H = 'H';
	static final char L = 'L';
	
	//bestResult, curBoard
	static final char LINE_H = 'h';
	static final char LINE_V = 'v';
	//start with l, cw 90
	static final char L_0 = 'a';
	static final char L_1 = 'b';
	static final char L_2 = 'c';
	static final char L_3 = 'd';
	
	static final char UP = 'U';
	static final char DOWN = 'D';
	static final char LEFT = 'L';
	static final char RIGHT = 'R';
	
	static char[][] bestResult = null;
	static char[][] curBoard = null;
	static char[][] board = null;
	static boolean[][] visited;
	static int count;
	static int bestLength;
	static int R;
	static int C;
	
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		int T = Integer.parseInt(reader.readLine());
		for (int t = 1; t <= T; t++){
			StringTokenizer tk = new StringTokenizer(reader.readLine());
			R = Integer.parseInt(tk.nextToken());
			C = Integer.parseInt(tk.nextToken());
			board = new char[R][C];
			reader.readLine();
			for (int r = 0; r < R; r++){
				reader.readLine();
				String line = reader.readLine();
				for (int c = 0; c < C; c++){
					boolean mid = line.charAt(4 * c + 2) == '*';
					boolean right = line.charAt(4 * c + 3) == '*';
					if (mid)
					{
						if (right) board[r][c] = H;
						else board[r][c] = L;
					}
					else board[r][c] = EMPTY;

				}
				reader.readLine();
				reader.readLine();
			}
			bestResult = new char[R][C];
			curBoard = new char[R][C];
			visited = new boolean[R][C];
			count = 0;
			bestLength = 100;
			
			dfs(UP, 0, 0, 0);
			dfs(LEFT, 0, 0, 0);
			
			if (count != 0)
			{
				out.print("+");
				for (int c = 0; c < C; c++) { out.print("---+"); }
				out.println();
				for (int r = 0; r < R; r++)
				{
					//first row
					out.print("|");
					for (int c = 0; c < C; c++)
					{
						switch (bestResult[r][c])
						{
						case LINE_V:
						case L_0: case L_3:
							out.print(" * ");
							break;
						default:
							out.print("   ");
							break;
						}
						out.print("|");
					}
					out.println();
					//second row
					out.print("|");
					for (int c = 0; c < C; c++)
					{
						switch (bestResult[r][c])
						{
						case LINE_V:
							out.print(" * ");
							break;
						case LINE_H:
							out.print("***");
							break;
						case L_0: case L_1:
							out.print(" **");
							break;
						case L_2: case L_3:
							out.print("** ");
							break;
						default:
							out.print("   ");
							break;
						}
						out.print("|");
					}
					out.println();
					//third row
					out.print("|");
					for (int c = 0; c < C; c++)
					{
						switch (bestResult[r][c])
						{
						case LINE_V:
						case L_1: case L_2:
							out.print(" * ");
							break;
						default:
							out.print("   ");
							break;
						}
						out.print("|");
					}
					out.println();
					
					out.print("+");
					for (int c = 0; c < C; c++) { out.print("---+"); }
					out.println();
				}
			}
			out.println("Number of solutions: " + count);
		}
		out.close();
	}
	
	static void p(char[][] board){
		for (int r=0;r<board.length;r++){
			for (int c=0;c<board[0].length;c++){
				System.out.print(board[r][c]);
			}	
			System.out.println();
		}
	}
	
	//'from', and arrive in [r,c], pathlength is from start, excluding r,c
	static void dfs(char from, int r, int c, int pathLength)
	{
		if ((r == R && c == C-1) || (r == R-1 && c == C))
		{
			if (bestLength > pathLength)
			{
				bestLength = pathLength;
				for (int i = 0; i < R; i++)
					for (int j = 0; j < C; j++)
						bestResult[i][j] = curBoard[i][j];
			}
			count++;
		}
		else
		{
			if (r < 0 || c < 0 || r >= R || c >= C ) return;
			if (board[r][c] == EMPTY || visited[r][c]) return;
			visited[r][c] = true;
			if (board[r][c] == H)
			{
				switch (from)
				{
				case UP:
					curBoard[r][c] = LINE_V;
					dfs(UP, r + 1, c, pathLength + 1);
					break;
				case DOWN:
					curBoard[r][c] = LINE_V;
					dfs(DOWN, r - 1, c, pathLength + 1);
					break;
				case LEFT:
					curBoard[r][c] = LINE_H;
					dfs(LEFT, r, c + 1, pathLength + 1);
					break;
				case RIGHT:
					curBoard[r][c] = LINE_H;
					dfs(RIGHT, r, c - 1, pathLength + 1);
					break;
				}
			}
			else
			{
				//L
				switch (from)
				{
				case UP:
					curBoard[r][c] = L_0;
					dfs(LEFT, r, c + 1, pathLength + 1);
					curBoard[r][c] = L_3;
					dfs(RIGHT, r, c - 1, pathLength + 1);
					break;
				case DOWN:
					curBoard[r][c] = L_1;
					dfs(LEFT, r, c + 1, pathLength + 1);
					curBoard[r][c] = L_2;
					dfs(RIGHT, r, c - 1, pathLength + 1);
					break;
				case LEFT:
					curBoard[r][c] = L_2;
					dfs(UP, r + 1, c, pathLength + 1);
					curBoard[r][c] = L_3;
					dfs(DOWN, r - 1, c, pathLength + 1);
					break;
				case RIGHT:
					curBoard[r][c] = L_1;
					dfs(UP, r + 1, c, pathLength + 1);
					curBoard[r][c] = L_0;
					dfs(DOWN, r - 1, c, pathLength + 1);
					break;
				}
			}
			curBoard[r][c] = EMPTY;
			visited[r][c] = false;
		}
	}
}