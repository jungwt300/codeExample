import java.util.Scanner;
public class vote {
	public static void main (String [] ags) {
		int [] election = new int[4];
			election[0] = 0;	//무효표
			election[1] = 0;	//1번 문재수
			election[2] = 0;	//2번 안찰스
			election[3] = 0;	//3번 레드준표
			
		Scanner sCan = new Scanner(System.in);
		int sel1 = 0;
		int sel2 = 0;
		
		System.out.println("20xx선거입니다.");
		while(true) {
		System.out.println("선거 참여 여부 : 1.한다 2.안한다 3.고민중 4.선거끝");
		sel1 = sCan.nextInt();
		
		switch (sel1) {
		case 1://선거 를 할경우 (1택)
			System.out.println("1.문재수 2. 안찰스 3. 레드준표 4. 무효 5. 투표종료");
			sel2 = sCan.nextInt();
			switch (sel2) {	
			case 1:
				System.out.println("1번 후보 선택");
				election[1] += 1;
				break;
			case 2:
				System.out.println("2번 후보 선택");
				election[2] += 1;
				break;
			case 3:
				System.out.println("3번 후보 선택");
				election[3] += 1;
				break;
			case 4:
				System.out.println("기권하셨습니다.");
				election[0] += 1;
				break;
			case 5:
				System.out.println("투표를 취소하였습니다.");
				break;
			default:
				System.out.println("잘못선택하셨습니다.");
				break;
				}
			break;
		case 2://선거를 안할경우(2택)
			System.out.println("선거에 참여하지 않았습니다.");
			break;
		case 3:
			System.out.println("고민중입니다.");
			break;
		case 4:
			System.out.println("20xx 선거가 모두 끝났습니다.");
			break;
		default:
			System.out.println("잘못선택하셨습니다.");
			break;
		}
		if (sel1 == 4) {
			System.out.println("선거 결과 발표");
		
			System.out.println("1번득표 :"+election[1]+",2번 독표:"+election[2]+",3번 득표:"+election[3]);
			if(election[1] >= election[2] && election[1] >= election[3]) {
				if(election[1]==election[2])
					System.out.println("최다 득표수인 1번후보와 2번후보의 득표수가 같습니다. 따라서 이번 투표는 무효입니다.");
				else if(election[1]==election[3])
					System.out.println("최다 득표수인 1번후보와 3번후보의 득표수가 같습니다. 따라서 이번 투표는 무효입니다.");
				else
				System.out.println("1번 후보 당선.");
			}
			else if(election[2] > election[1] && election[2] > election[3])
				System.out.println("2번 후보 당선.");
			else if(election[3] > election[1] && election[3] > election[2])
				System.out.println("3번 후보 당선.");
			break;
			}
		}
	}
}