using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GameCaro
{
    public class ChessBoardManager
    {
        #region Properties
        public Panel chessBoard;
        private  Panel ChessBoard
        {
          get{ return chessBoard;}
          set{ chessBoard = value;}
        }
        private List<Player> player;
        public List<Player> Players
        {
            get { return player; }
            set { player = value; }
        }
        private int currentplayer; // Biến tương ứng với player hiện tại
        public int CurentPlayer
        {
            get { return currentplayer; }
            set { currentplayer = value; }
        }
        private TextBox playerName;
        public TextBox PlayerName
        {
            get { return playerName; }
            set { playerName = value; }
        }
        private PictureBox playerMark;
        public PictureBox PlayerMark
        {
            get { return playerMark; }
            set { playerMark = value; }
        }
        private List<List<Button>> matrix;
        public List<List<Button>> Matrix
        {
            get { return matrix; }
            set { matrix = value; }
        }
        #endregion

        #region Initialize
        public ChessBoardManager(Panel chessBoard, TextBox playerName, PictureBox mark) // Tạo đối tượng người chơi
        {
            this.chessBoard = chessBoard;
            this.PlayerName = playerName;
            this.playerMark = mark;
            this.Players = new List<Player>()
            {
                new Player("Player_1", Image.FromFile(Application.StartupPath + "\\Resources\\X.png")),
                new Player("Player_2", Image.FromFile(Application.StartupPath + "\\Resources\\O.png"))
            };
            CurentPlayer = 0;
            ChangePlayer();
        }
        #endregion

        #region Method
        public void DrawChessBoard()  // Hàm vẽ bàn cờ
        {
            Matrix = new List<List<Button>>(); // Danh sách nút tạo nên ma trận
            Button oldButton = new Button() { Width = 0, Location = new Point(0, 0) }; // Set vị trí và kích thước của oldButton
            for (int i = 0; i < 14; i++)
            {
                Matrix.Add(new List<Button>()); // Tạo mảng mới để lưu
                for (int j = 0; j < 14; j++)
                {
                    Button btn = new Button()
                    {
                        Width = Cons.CHESS_WIDTH,
                        Height = Cons.CHESS_HEIGHT,
                        Location = new Point(oldButton.Location.X + Cons.CHESS_WIDTH, oldButton.Location.Y),
                        BackgroundImageLayout = ImageLayout.Stretch, // Chỉnh layout theo kích thước button
                        Tag = i.ToString() // Biến lưu vị trí của button
                    };
                    btn.Click += btn_Click;  // Sự kiện khi click vào nút
                    chessBoard.Controls.Add(btn);  
                    Matrix[i].Add(btn); 
                    oldButton = btn; 
                }
                oldButton.Location = new Point(0, oldButton.Location.Y + Cons.CHESS_HEIGHT);
                oldButton.Width = 0;
                oldButton.Height = 0;
            }

        }

        void btn_Click(object sender, EventArgs e)
        {
            Button btn = sender as Button; // Ép kiểu button cho một sender
            if (btn.BackgroundImage != null)
                return;
            Mark(btn);
            ChangePlayer();
            if(isEndGame(btn))
            {
                EndGame();
            }
        }
        private void EndGame()
        {
            MessageBox.Show("Kết thúc Game!");
        }
        //private void NewGame()
        //{
        //    ChessBoard.DrawChessBoard();
        //}
        private void Quit()
        {
            Application.Exit();
        }
        private bool isEndGame(Button btn)
        {
            return isEndNgang(btn) || isEndDoc(btn) || isEndPrimary(btn) || isEndSub(btn);
        }
        private Point GetChessPoint(Button btn) // Lấy tọa độ button
        {
            
            int vertical = Convert.ToInt32(btn.Tag);
            int horizontal = Matrix[vertical].IndexOf(btn);
            Point point = new Point(horizontal, vertical);
            return point;
        }
        private bool isEndNgang(Button btn)
        {
            Point point = GetChessPoint(btn);
            int countLeft = 0;
            for(int i = point.X; i >= 0; i--)
            {
                if (Matrix[point.Y][i].BackgroundImage == btn.BackgroundImage)
                {
                    countLeft++;
                }
                else
                    break;
            }
            int countRight = 0;
            for (int i = point.X + 1; i < Cons.CHESS_WIDTH; i++)
            {
                if (Matrix[point.Y][i].BackgroundImage == btn.BackgroundImage)
                {
                    countRight++;
                }
                else
                    break;
            }

            return countLeft + countRight == 5;
        }
        private bool isEndDoc(Button btn)
        {
            Point point = GetChessPoint(btn);
            int countTop = 0;
            for (int i = point.X; i >= 0; i--)
            {
                if (Matrix[i][point.X].BackgroundImage == btn.BackgroundImage)
                {
                    countTop++;
                }
                else
                    break;
            }
            int countDown = 0;
            for (int i = point.X + 1; i <= Cons.CHESS_HEIGHT; i++)
            {
                if (Matrix[i][point.X].BackgroundImage == btn.BackgroundImage)
                {
                    countDown++;
                }
                else
                    break;
            }

            return countTop + countDown == 5;
        }
        private bool isEndPrimary(Button btn) // Kiểm tra chéo chính
        {
            Point point = GetChessPoint(btn); // lấy tọa độ button hiện tại
            int countTopC = 0;
            for (int i = 0; i <= point.X; i++)
            {   if (point.X - i < 0 || point.Y - i < 0)
                    break;
                if (Matrix[point.Y - i][point.X - i].BackgroundImage == btn.BackgroundImage)
                {
                    countTopC++;
                }
                else
                    break;
            }
            int countDownC = 0;
            for (int i = 1; i <= Cons.CHESS_WIDTH - point.X; i++)
            {
                if (point.Y + i >= Cons.CHESS_HEIGHT || point.X + i >= Cons.CHESS_WIDTH)
                    break;
                if (Matrix[point.Y + i][point.X + i].BackgroundImage == btn.BackgroundImage) //KT
                {
                    countDownC++;
                }
                else
                    break;
            }

            return countTopC + countDownC == 5;
        }
        private bool isEndSub(Button btn) // Kiểm tra chéo phụ
        {
            Point point = GetChessPoint(btn);
            int countTopP = 0;
            for (int i = 0; i <= point.X; i++)
            {
                if (point.X + i > Cons.CHESS_WIDTH || point.Y - i < 0)
                    break;
                if (Matrix[point.Y - i][point.X + i].BackgroundImage == btn.BackgroundImage)
                {
                    countTopP++;
                }
                else
                    break;
            }
            int countDownP = 0;
            for (int i = 1; i <= Cons.CHESS_WIDTH - point.X; i++)
            {
                if (point.Y + i >= Cons.CHESS_HEIGHT || point.X - i < 0)
                    break;
                if (Matrix[point.Y + i][point.X - i].BackgroundImage == btn.BackgroundImage)
                {
                    countDownP++;
                }
                else
                    break;
            }

            return countTopP + countDownP == 5;
        }
        private void Mark(Button btn)
        {
            btn.BackgroundImage = Players[CurentPlayer].Mark;
            CurentPlayer = CurentPlayer == 1 ? 0 : 1;
        }
        private void ChangePlayer()
        {
            PlayerName.Text = Players[CurentPlayer].Name;
            playerMark.Image = Players[CurentPlayer].Mark;
        }
    }
    #endregion

}
