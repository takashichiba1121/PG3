using namespace std;

//�P�������X�g�̍\���̂̒�`
typedef struct CELL {
	char val[16];
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
	void push_back(char* val);

	//�f�[�^���w�肵���Z���ɒǉ�����֐��̃v���g�^�C�v�錾
	void create(int itr,char* val);

	void Dit(int itr, char* val);

	//�ꗗ��\������֐��̃v���g�^�C�v�錾
	void index();

	void print(int itr);

	int Get();

	void Delete(int itr);

private:
	CELL head;
	
};
