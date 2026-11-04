*This project has been created as part of the 42 curriculum by chchoi.*

### Description
* C 언어에서 사용되는 유용한 함수를 직접 구현
* 문자열/메모리 처리, 문자 판별, 동적 할당, 출력, 연결 리스트 기능을 제공
* 구현한 함수의 사용법과 원리의 이해

### Instructions
* make all - c파일들을 object파일로 컴파일 한 후 libft.a로 만듬
* make clean - object 파일을 전부 제거함.
* make fclean - all 작업을 통해서 생성된 모든 작업 파일을 제거함.
* make re - fclean 수행 후 all 수행

### Resources
* man function
* glibc 저장소 - https://github.com/bminor/glibc
* bsd 저장소 - https://github.com/openbsd
* 각종 블로그 포스트

#### AI 사용
이 프로젝트에서 AI는 학습 및 디버깅을 보조하는 도구로 사용하였다.
주요 사용 용도는 다음과 같다.
- C 표준 라이브러리 함수의 동작과 C 언어 개념 확인
- 경계값 및 예외적인 입력을 포함한 테스트 케이스 검토 및 추가 테스트 케이스 구성
- 테스트 실패 및 예상하지 못한 동작의 원인 분석
- 사설 테스터의 테스트 케이스와 원본 함수의 동작 비교
- 프로젝트 Subject의 요구사항 확인 및 해석
- 구현 방법 검토 및 작성한 코드에서 발생할 수 있는 문제점 확인

### 과제에서 인상적인 부분

#### 정수 승격과 산술 변환

##### - 승격 법칙
- `char`, `unsigned char`, `short` 등의 작은 정수형은 연산이나 비교 과정에서 `int` 등의 타입으로 승격될 수 있다. 단 모든 값을 표현하지 못한 경우 `unsigned int`로 승격됨.
- 서로 다른 타입의 경우 통상 산술 변환 발생. 지정된 정수 변환 순위에 따라 타입이 바뀌어 계산됨.
- `(unsigned char)a - (unsigned char)b`와 같은 연산에서도 캐스팅 이후 실제 산술 연산을 수행할 때 정수 승격이 발생한다.
- signed 정수형과 unsigned 정수형을 함께 연산하거나 비교할 경우 usual arithmetic conversions에 의해 예상하지 못한 타입 변환이 발생할 수 있다.
- `size_t`와 같은 unsigned 정수형에서는 `0 - 1`이나 `(size_t)-1`과 같은 연산의 결과가 큰 양수로 표현될 수 있다.

#### char와 unsigned char

- `memcmp`, `memchr` 등의 메모리 관련 함수에서는 메모리의 각 바이트를 `unsigned char` 값으로 취급한다.
- `char`가 signed인 환경에서는 `0x80` 이상의 바이트가 음수로 해석될 수 있으므로 비교 결과에 영향을 줄 수 있다.
- `memchr`의 검색값 역시 `unsigned char`에 해당하는 값으로 변환하여 비교한다.

#### static, extern과 Linkage
- 파일 범위에서 선언된 식별자가 모두 동일한 방식으로 외부에 노출되는 것은 아니다.
- `static`을 사용하면 internal linkage를 가지므로 해당 translation unit 내부에서만 접근할 수 있다.
- external linkage를 가지는 심볼은 다른 translation unit에서도 참조할 수 있다.
- `extern`을 통해 다른 위치에서 정의된 객체나 함수를 참조할 수 있다.
- 정적 라이브러리(`.a`)에 object file을 포함시키는 것만으로 각 함수가 자동으로 private이 되는 것은 아니다.

#### glibc ctype 계열의 구현

- glibc의 `isalpha()` 등의 문자 분류 함수는 단순한 문자 범위 비교만으로 구현되어 있지 않다.
- 문자별 속성을 나타내는 분류 테이블과 비트 플래그를 이용하여 문자의 속성을 판별하는 구조를 사용한다.
- `_ISupper`, `_ISlower`, `_ISalpha`, `_ISbit()` 등의 값이 문자 분류에 사용된다.
- 표준 `isalpha()`는 참인 경우 반드시 `1`을 반환해야 하는 것은 아니다.
- Libft의 `ft_isalpha` 등의 함수는 Subject의 요구사항에 따라 참이면 `1`, 거짓이면 `0`을 반환해야 한다.

#### strchr

- `strchr`에서는 문자열을 구성하는 문자뿐만 아니라 문자열 끝의 `'\0'`도 검색 대상이 된다.
- 따라서 `strchr(s, '\0')`은 문자열의 마지막 NUL 문자의 주소를 반환한다.
- 검색할 `int` 값은 문자 비교에 적합한 값으로 변환되어 처리된다.

#### memcpy와 memmove

- `memcpy`는 source와 destination 영역이 겹치지 않는 경우의 메모리 복사를 수행한다.
- `memmove`는 메모리 영역이 겹치는 경우에도 원본 데이터가 손상되지 않도록 복사한다.
- 같은 동작을 목적으로 하나 지향하는 바의 차이에서 구분됨. dst랑 src가 겹쳐도 되냐 안되냐의 차이로 갈라져서 쌍둥이 탄생

#### 구현할 수 있어도 가급적 헤더를 쓰는 이유
찾기 시작한 원인은 size_t
-> 정확히는 __SIZE_MAX__ 때문
__SIZE_MAX__는 컴파일러에 지정된 매크로임.
모든 컴파일러에서 __SIZE_MAX__를 보장하지 않음
MSVC의 경우 윈도우 스타일로 불린다함.(나도 안봄)
즉 컴파일러, 툴체인 제작자가 작업해둔 결과물이 해당 헤더.
위에 작업물을 만들기 위해서는 해당 작업이 필요하기에
인터페이스 얻어 이식성이 좋다는건 여기서 나오는 말.

#### 그럼 헤더로 인하여 이식성이 보장되는 이유
- 명령어때와 마찬가지로 컴파일러도 결국 프로그램이며 명령어처럼 동작한다.
- 컴파일러 제공자가 기계 명령어나 OS따른 기능을 정의해둔 부분. 거의 모든 헤더가 공통적으로 불릴 수 있는 이유.
- 다만 출력기능같이 운영체제랑 엮여있는 부분은 프로토콜에 따라 제공이 안될 수도있음. 운영체제는 규격을 다중 상속한 클래스라 보면 비슷함.

#### const type* const v
- 보통 const type v로 쓰는데 type const v도 가능
- 단순 묘기는 아니고 const type* const v도 가능함.
 즉, 변수 선언에 사용되던 키워드에 1:1 대응한다는 것.
 const 변수를 조작하려고 형변환한건 어찌보면 당연했던 것.
- ex1. js의 const가 type* const v와 비슷한 느낌. v의 위치 수정은 안되나 내부 값 수정은 가능
- ex2. const type* const v로 모든 수정 봉인 가능

#### 사전 오버플로우 검사
1. 덧셈 오버플로 방지
- if (len2 > SIZE_MAX - len1 - 1)
-   return (NULL);

2. 곱셈 오버플로 방지
- if (count > SIZE_MAX / size)
-   return (NULL);
- 기억나는 수학나옴.

/*

*/