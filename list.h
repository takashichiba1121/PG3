using namespace std;

//�P�������X�g�̍\���̂̒�`
typedef struct CELL {
	char station[16];
	struct CELL* prev;
	struct CELL* next;
}CELL;

class List
{
public:
	List();

	//�}���������Z���̃A�h���X���擾
	CELL* getInswrtCellAddress(int iterator);
	//�f�[�^�𖖔��ɒǉ�����֐��̃v���g�^�C�v�錾
	void push_back(char* station);

	//�f�[�^���w�肵���Z���ɒǉ�����֐��̃v���g�^�C�v�錾
	void create(int itr,char* station);

	//�ꗗ��\������֐��̃v���g�^�C�v�錾
	void index();

	void print(int itr);

	int Get();

private:
	CELL head;
};
