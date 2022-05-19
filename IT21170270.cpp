/* 	IT21170270
	Maduranga D.B.W.N
	Malabe
	8.2.g1
  MLB_08.02_3
  Online Laundry Service

I have programmed the classes "Payment", "Invoice", "Report"  and their relationships.
"Payment" Class has whole part relationship(composition) with "Invoice" Class.
"Invoice" Class has a Association relationship(Uni-Directional) with "Report" Class.

I did comment some code because if not it gives some error like class is not defined.

Collaboration with other group members' classes

Maduranga D.B.W.N (IT21170270)-->
   *Payment
   *Invoice
   *Report
   

Sumanasekara P.D.M (IT21167300) -->
   *Order
   *Cart
   *Laundary_Item

I.U.N.Nadeeshan (IT21166556) -->
   *Staff_Memeber
   *Accountant
   *User
   *Inquiry

M.G.T Rashmika (IT21167546) -->
   *Delivery_Person
   *Feedback
   *Notification
   
Gamlathge G.G.A.U (IT21173868) -->
   *Package
   *Subscription
   *Customer
               
*/

#include <iostream>
#include <string>

#define MAX_REPORT_INVOICE_QUANTITY 10
#define MAX_REPORT_ORDER_QUANTITY 10

using namespace std;

/*-----------------------------Invoice Class Header--------------------------------*/
class Invoice {
  private:
    string invoiceNo;            //aggrigation with Payment Class
   // Customer *customer;       //association with Cusatomer Class
   // Accountant *accountant;     //association with Accountant Class
    
  public:
    Invoice();
    Invoice(string no);
	void display(); 
    void getOrderDetails();
	void getCustomerDetails();
	void getPaymentDetails();
	~Invoice();		
};


/*-----------------------------Report Class Header--------------------------------*/

class Report
{
	private:
		string reportID;
		string reportType;
	  Invoice *invoice[MAX_REPORT_INVOICE_QUANTITY];   //aggrigation with Payment Class
	  //Order *order[MAX_REPORT_ORDER_QUANTITY];       //association with Payment Class
		   
	public:
	    Report();
		Report(string ID , string );
		void display();
		void displayOrdersReports();
		void displayInvoiceReports();
		void displayLaundaryItemReports();	
};

/*-----------------------------Payment Class Header--------------------------------*/
class Payment
{
	private:
		Invoice *invoice;   //aggrigation with Invoice Class
		string paymentID;
		string paymentType;
		string PaymentDate;
		
	public:	
        Payment();
		Payment(string payID , string payType , string patDate , string No );
		void display();
		void validatePayment();
		void getOrderDetails();
		~Payment();
};

/*-----------------------------Inquiry Class Header--------------------------------*/

class Inquiry
{
	private:
		int inquiryNo;
	
	public:
	    Inquiry();
		Inquiry(int no);
		display();
	    //void getCustomerDetails(Customer *customer);
		void setInquiryReply();	
};

/*-----------------------------Report class Implemnetation--------------------------------*/

Report::Report()
{
	 reportType = "";
	reportID = "";	
}

Report::Report(string ID , string type)
{
	reportID = ID;
	reportType = type;   
}

void Report:: display()
{
	cout << endl << "Report Infro ->" << endl ;
	cout << "Report ID   : " << reportID << endl ;
    cout <<"Report Type : " << reportType << endl ;	
}

void Report::displayOrdersReports()
{
	
}
void displayInvoiceReports()
{
	
}
void displayLaundaryItemReports()
{
	
}

/*-----------------------------Invoice class Implemnetation--------------------------------*/

Invoice::Invoice()

{
	invoiceNo = ""; 
}

Invoice::Invoice(string No)
{
	invoiceNo = No ;
}

void Invoice::display()
{
	cout << "Invoice No   : " << invoiceNo << endl ;	
}


void Invoice::getOrderDetails()
{
	
}

void Invoice::getCustomerDetails()
{	

}

void Invoice::getPaymentDetails()
{
	
}

Invoice::~Invoice()
{
		cout << "Deleted Invoice " << invoiceNo << endl ;
}

/*-----------------------------Payment class implementation--------------------------------*/

Payment::Payment()
{
	invoice = new Invoice("");
	paymentID = "" ;
	paymentType = "";
	PaymentDate = "";	
}

Payment::Payment(string payID , string payType , string payDate , string No)
{
    invoice = new Invoice(No);
    paymentID = payID ;
	paymentType = payType;
	PaymentDate = payDate;	
}

void Payment::display()
{
	cout << "Payment Infro ->" << endl ;
	cout << "Patment ID   : " << paymentID << endl ;
    cout <<"Payment Type : " << paymentType << endl ;
	cout << "payment Date : " << PaymentDate << endl << endl ;
	cout << "Invoice Infor ->" << endl ;
	invoice->display();
}

void Payment::validatePayment()
{
	
}

void Payment::getOrderDetails()
{
	
}

Payment::~Payment()
{
	cout << "Deleted Payment " << paymentID << endl ;
	delete invoice;			
}


int main(void)
{	

/*-----------------------------Payment class--------------------------------*/
 
	Payment * payObj;
	payObj = new Payment("P1020" , "Paypal" , "2021/05/20" , "I1020");
	payObj -> display();  //Display sample details
	//delete payObj;
	
/*-----------------------------Report class--------------------------------*/
  
   Report * repoObj1;
   repoObj1 = new Report("R567" , "InvoiceFile");
   repoObj1->display();   //Display sample details
   delete repoObj1 ;
   
//Invoice objects allready define inside the payment class   


	return 0;
}

