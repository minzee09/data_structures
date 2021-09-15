//
// ���α׷� ����: token�� �а�, ����ϰ�, �м��ϴ� token ADT�� �����ϰ� �����ϴ� ���α׷�
//				  (2���� ��ū�� ��������, ��ū 2���� ��ġ��, ��ū�� ������ ������ ��ȯ ���� ��� ����)
//


#define SWAP(x, y, t) (t=x, x=y, y=t)

//------------------< Constructor >---------------------
token::token()
{	
	length = 0; //clear();	setLength(0);
}

//------------------< Destructor  >---------------------
token::~token()
{
	length = 0; //clear();	setLength(0);
}

void token::setLength(int len)
{
	length = len;
}

void token::setElement()
{
	tokenData c;
	
	while (1)
	{
		// cin >> c; //�����̽� �� ���� Ű ����
		cin.get(c); //�����̽� �� ���� Ű �˻�
		//���������� �ƴϸ� �߰�
		if (c != ' ' && c != '\n' && length < Max)
			element[length++] = c; //����: ++���� ����/�ΰ� ����?
		//���������̸� ����
		else break;
	}
	element[length] = '\0';

	// ������ �Է� ������ ó�� 	
	if ( c != '\n')
		cin.ignore (80,'\n');

	//  Ȥ��
	//	while ( c != '\n' )	
	//		cin.get(c);
}

int token::getLength()
{
	return length;
}

//���ڿ� ���
void token::getElement()
{
	cout << "<";
	for (int i = 0; i < length; i++)
		cout << element[i];
	cout << ">";
}
//������ ��� ����
void token::clear()
{
	length = 0;
}
//�� ���� ��ū�� ������ ��
bool token::isEqual(token t2)
{
	bool  equal;
	//���� ������ �� -> �ٸ��� �����
	if (length == t2.length)
	{
		equal = true;
		for (int i = 0; i < length; i++)
		{
			//�� ��ū�� ���Ұ� �� -> �ٸ��� false
			if (element[i] != t2.element[i])
			{
				equal = false;
				break;
			}
		}
	}
	//���� �ٸ��� false
	else
	{
		equal = false;
	}
	return equal;
}
//�� ��ū�� ��ġ��
void token::merge (token t2)
{
	int limit;
	//limit ���
	limit = Max - length;
	if (t2.length < limit)
		limit = t2.length;

	//���� ��ū �ڿ� ��ū t2�� �߰�
	for (int i = 0; i < limit; i++)
	{
		element[length] = t2.element[i];
		length++;
	}
	//�ι��� �߰� (�����ٴ� ǥ��)
	element[length] = '\0';
}
//��ū�� ������ ������ ���
void token::reverse()
{
	int temp;
	for (int i = 0; i < length / 2; i++) //i < length ->����ġ
	{
		//��ū�� �Ǿհ� �ǳ����� ������� �ڸ� �ٲ��ֱ�
		SWAP(element[i], element[length - 1 - i], temp);
	}
}
//���������� ��ȯ
long token::intValue ()
{
	long value = 0;
	for (int i = 0; i < length; i++)
		value = value * 10 + ((int)element[i] - (int)'0'); //value * 10�ϴ� ����: �������� ���¿��� ���Ұ� ������� �����Ǳ� ����

	return value;
}
//from���� count���� ���ڿ��� ���� ��ū sub�� ����
void token::subToken(token &sub, int from, int count)
{
	for (int i = 0; i < count; i++)
	{
		sub.element[i] = element[from - 1];
		sub.length++;
		from++;
	}
	//�ι��� �߰� (�����ٴ� ǥ��)
	sub.element[length] = '\0';
}
//�� ���� ��ū�� ���� �������� ���ϴ� �Լ�(����->if��, for�� ���)
bool token::isReverse1(token t2)
{
	bool result;
	//���� ������ �� -> �ٸ��� �����
	if (length == t2.length)
	{
		result = true;
		for (int i = 0; i < length; i++)
		{
			//�� ��ū�� ���Ұ� �� -> �ٸ��� false
			if (element[i] != t2.element[length - 1 - i])
			{
				result = false;
				break;
			}
		}
	}
	//���� �ٸ��� false
	else
	{
		result = false;
	}
	return result;
}
//�� ���� ��ū�� ���� �������� ���ϴ� �Լ�(ADT �Լ��� ȣ��θ� ����)
bool token::isReverse2(token t2)
{
	bool result;
	//��ū ���� ��ȯ �Լ� ȣ�� ->this ��ū�� ����
	reverse();
	//�ΰ��� ��ū�� �������� ��
	result = isEqual(t2);

	return result;
}