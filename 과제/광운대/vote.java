import java.util.Scanner;
public class vote {
	public static void main (String [] ags) {
		int [] election = new int[4];
			election[0] = 0;	//��ȿǥ
			election[1] = 0;	//1�� �����
			election[2] = 0;	//2�� ������
			election[3] = 0;	//3�� ������ǥ
			
		Scanner sCan = new Scanner(System.in);
		int sel1 = 0;
		int sel2 = 0;
		
		System.out.println("20xx�����Դϴ�.");
		while(true) {
		System.out.println("���� ���� ���� : 1.�Ѵ� 2.���Ѵ� 3.����� 4.���ų�");
		sel1 = sCan.nextInt();
		
		switch (sel1) {
		case 1://���� �� �Ұ�� (1��)
			System.out.println("1.����� 2. ������ 3. ������ǥ 4. ��ȿ 5. ��ǥ����");
			sel2 = sCan.nextInt();
			switch (sel2) {	
			case 1:
				System.out.println("1�� �ĺ� ����");
				election[1] += 1;
				break;
			case 2:
				System.out.println("2�� �ĺ� ����");
				election[2] += 1;
				break;
			case 3:
				System.out.println("3�� �ĺ� ����");
				election[3] += 1;
				break;
			case 4:
				System.out.println("����ϼ̽��ϴ�.");
				election[0] += 1;
				break;
			case 5:
				System.out.println("��ǥ�� ����Ͽ����ϴ�.");
				break;
			default:
				System.out.println("�߸������ϼ̽��ϴ�.");
				break;
				}
			break;
		case 2://���Ÿ� ���Ұ��(2��)
			System.out.println("���ſ� �������� �ʾҽ��ϴ�.");
			break;
		case 3:
			System.out.println("������Դϴ�.");
			break;
		case 4:
			System.out.println("20xx ���Ű� ��� �������ϴ�.");
			break;
		default:
			System.out.println("�߸������ϼ̽��ϴ�.");
			break;
		}
		if (sel1 == 4) {
			System.out.println("���� ��� ��ǥ");
		
			System.out.println("1����ǥ :"+election[1]+",2�� ��ǥ:"+election[2]+",3�� ��ǥ:"+election[3]);
			if(election[1] >= election[2] && election[1] >= election[3]) {
				if(election[1]==election[2])
					System.out.println("�ִ� ��ǥ���� 1���ĺ��� 2���ĺ��� ��ǥ���� �����ϴ�. ���� �̹� ��ǥ�� ��ȿ�Դϴ�.");
				else if(election[1]==election[3])
					System.out.println("�ִ� ��ǥ���� 1���ĺ��� 3���ĺ��� ��ǥ���� �����ϴ�. ���� �̹� ��ǥ�� ��ȿ�Դϴ�.");
				else
				System.out.println("1�� �ĺ� �缱.");
			}
			else if(election[2] > election[1] && election[2] > election[3])
				System.out.println("2�� �ĺ� �缱.");
			else if(election[3] > election[1] && election[3] > election[2])
				System.out.println("3�� �ĺ� �缱.");
			break;
			}
		}
	}
}