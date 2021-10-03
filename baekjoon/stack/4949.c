#include <stdio.h>

void init(int *s, int *b, int *e ,int *err, int *i)
{
	*s = 0;
	*b = 0;
	*e = 0;
	*err = 0;
	*i = 0;
	return ;
}

int main(void)
{
	char c; // 띄어쓰기가 있어  한글자씩 확인
	char before[101] = {0}; // 이전 괄호 저장
	int end; // 끝의 위치
	int small; // 소괄호 개수 파악
	int big; // 대괄호 개수 파악
	int error; // 에러 처리
	int i; // 이전 괄호 인덱스

	init(&small, &big, &end, &error, &i); // 초기화
	while (42)
	{
		scanf("%c", &c);
		if (end == 1 && c == '.') // 처음 . 이 들어오면 종료
			return (0);
		if (end > 1 && c == '.') // 문장의 마지막인 경우
		{
			if (small || big) // 괄호의 개수가 맞지 않는 경우 에러처리
				error = 1;
			if (error == 0) // 에러 없으면 yes
				printf("yes\n");
			else  // 에러이면 no
				printf("no\n");
			init(&small, &big, &end, &error, &i);
			// 다음 문장 받기 전 초기화
			continue ; // 다음 문장 진행
		}
		if (c == '(')
		{
			small++;
			before[i++] = '('; //이후 괄호 닫힘 확인
		}
		else if (c == ')')
		{
			small--;
			if (small < 0 || before[i - 1] == '[')// 닫히는 괄호가 많거나
				error = 1; // 대괄호가 열린상태로 소괄호가 닫히면 에러
            if (i > 1)
			    before[--i] = 0; // 괄호의 짝을  맞춰 괄호 제거
		}
		else if (c == '[')
		{
			big++;
			before[i++] = '['; // 이후 닫히는 괄호 확인
		}
		else if (c == ']')
		{
			big--;
			if (big < 0 || before[i - 1] == '(') // 닫히는 괄호가 많거나
				error = 1; // 소괄호가 열린상태로 대괄호가 닫히면 에러
            if (i > 1)
			    before[--i] = 0; // 괄호의 짝을 맞춰 괄호 제거
		}
        end++; // 끝의 위치 ++
	}
}
