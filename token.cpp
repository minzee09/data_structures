//
// 프로그램 설명: token을 읽고, 출력하고, 분석하는 token ADT를 정의하고 구현하는 프로그램
//				  (2개의 토큰이 동일한지, 토큰 2개를 합치기, 토큰의 내용을 역으로 반환 등의 기능 구현)
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
		// cin >> c; //스페이스 및 엔터 키 무시
		cin.get(c); //스페이스 및 엔터 키 검사
		//종료조건이 아니면 추가
		if (c != ' ' && c != '\n' && length < Max)
			element[length++] = c; //질문: ++붙인 이유/널값 때문?
		//종료조건이면 종료
		else break;
	}
	element[length] = '\0';

	// 나머지 입력 데이터 처리 	
	if ( c != '\n')
		cin.ignore (80,'\n');

	//  혹은
	//	while ( c != '\n' )	
	//		cin.get(c);
}

int token::getLength()
{
	return length;
}

//문자열 출력
void token::getElement()
{
	cout << "<";
	for (int i = 0; i < length; i++)
		cout << element[i];
	cout << ">";
}
//내용을 모두 삭제
void token::clear()
{
	length = 0;
}
//두 개의 토큰이 같은지 비교
bool token::isEqual(token t2)
{
	bool  equal;
	//길이 같으면 비교 -> 다를때 벗어나기
	if (length == t2.length)
	{
		equal = true;
		for (int i = 0; i < length; i++)
		{
			//두 토큰의 원소값 비교 -> 다르면 false
			if (element[i] != t2.element[i])
			{
				equal = false;
				break;
			}
		}
	}
	//길이 다르면 false
	else
	{
		equal = false;
	}
	return equal;
}
//두 토큰을 합치기
void token::merge (token t2)
{
	int limit;
	//limit 계산
	limit = Max - length;
	if (t2.length < limit)
		limit = t2.length;

	//현재 토큰 뒤에 토큰 t2를 추가
	for (int i = 0; i < limit; i++)
	{
		element[length] = t2.element[i];
		length++;
	}
	//널문자 추가 (끝났다는 표시)
	element[length] = '\0';
}
//토큰의 내용을 역으로 출력
void token::reverse()
{
	int temp;
	for (int i = 0; i < length / 2; i++) //i < length ->원위치
	{
		//토큰의 맨앞과 맨끝부터 순서대로 자리 바꿔주기
		SWAP(element[i], element[length - 1 - i], temp);
	}
}
//정수값으로 반환
long token::intValue ()
{
	long value = 0;
	for (int i = 0; i < length; i++)
		value = value * 10 + ((int)element[i] - (int)'0'); //value * 10하는 이유: 정수형인 상태에서 원소가 순서대로 나열되기 위해

	return value;
}
//from부터 count개의 문자열을 공백 토큰 sub에 복사
void token::subToken(token &sub, int from, int count)
{
	for (int i = 0; i < count; i++)
	{
		sub.element[i] = element[from - 1];
		sub.length++;
		from++;
	}
	//널문자 추가 (끝났다는 표시)
	sub.element[length] = '\0';
}
//두 개의 토큰이 서로 역순인지 비교하는 함수(루핑->if문, for문 사용)
bool token::isReverse1(token t2)
{
	bool result;
	//길이 같으면 비교 -> 다를때 벗어나기
	if (length == t2.length)
	{
		result = true;
		for (int i = 0; i < length; i++)
		{
			//두 토큰의 원소값 비교 -> 다르면 false
			if (element[i] != t2.element[length - 1 - i])
			{
				result = false;
				break;
			}
		}
	}
	//길이 다르면 false
	else
	{
		result = false;
	}
	return result;
}
//두 개의 토큰이 서로 역순인지 비교하는 함수(ADT 함수의 호출로만 구현)
bool token::isReverse2(token t2)
{
	bool result;
	//토큰 역순 변환 함수 호출 ->this 토큰에 적용
	reverse();
	//두개의 토큰이 같은지를 비교
	result = isEqual(t2);

	return result;
}