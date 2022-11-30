using namespace std;

//単方向リストの構造体の定義
typedef struct CELL {
	char station[16];
	struct CELL* prev;
	struct CELL* next;
}CELL;

class List
{
public:
	List();

	//挿入したいセルのアドレスを取得
	CELL* getInswrtCellAddress(int iterator);
	//データを末尾に追加する関数のプロトタイプ宣言
	void push_back(char* station);

	//データを指定したセルに追加する関数のプロトタイプ宣言
	void create(int itr,char* station);

	//一覧を表示する関数のプロトタイプ宣言
	void index();

	void print(int itr);

	int Get();

private:
	CELL head;
};
