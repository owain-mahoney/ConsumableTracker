#pragma once
namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace std;


	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}
		int^ itemID;
		String^ ID;
	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::TextBox^ txtLocation;
	private: System::Windows::Forms::TextBox^ txtQuanity;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ Display;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtLocation = (gcnew System::Windows::Forms::TextBox());
			this->txtQuanity = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Display = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Display))->BeginInit();
			this->SuspendLayout();
			// 
			// txtLocation
			// 
			this->txtLocation->Location = System::Drawing::Point(77, 94);
			this->txtLocation->Name = L"txtLocation";
			this->txtLocation->Size = System::Drawing::Size(150, 26);
			this->txtLocation->TabIndex = 1;
			this->txtLocation->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::txtLocation_KeyDown);
			// 
			// txtQuanity
			// 
			this->txtQuanity->Location = System::Drawing::Point(77, 185);
			this->txtQuanity->Name = L"txtQuanity";
			this->txtQuanity->Size = System::Drawing::Size(150, 26);
			this->txtQuanity->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(73, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Location";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(73, 143);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Quanity";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(77, 235);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 39);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Update";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Display
			// 
			this->Display->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Display->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Display->Location = System::Drawing::Point(281, 67);
			this->Display->Name = L"Display";
			this->Display->RowHeadersWidth = 62;
			this->Display->RowTemplate->Height = 28;
			this->Display->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->Display->Size = System::Drawing::Size(737, 457);
			this->Display->TabIndex = 6;
			this->Display->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::Display_CellDoubleClick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1030, 708);
			this->Controls->Add(this->Display);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtQuanity);
			this->Controls->Add(this->txtLocation);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Display))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		
		
		if (txtQuanity->Text != "")
		{
			String^ config = L"datasource=127.0.0.1; port=3306; username=root; password=eggs;";
			MySqlConnection^ condb = gcnew MySqlConnection(config);

			try {
				MySqlCommand^ query = gcnew MySqlCommand("UPDATE EquipmentTracker.location SET Quantity = " + txtQuanity->Text + " WHERE ID = " + "'" + ID + "'" + " AND ItemID = " + itemID + "; ", condb);
				condb->Open();
				int rowUpdated = query->ExecuteNonQuery();
				if (rowUpdated > 0)
				{
					MessageBox::Show("updated");
				}
				else
				{
					MessageBox::Show("Error this needs to have value ");
				}
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->ToString());
			};
			
		}

			
		else
		{
			MessageBox::Show("Error this needs to have value ");
		}

		
		String^ config = L"datasource=127.0.0.1; port=3306; username=root; password=eggs;";
		MySqlConnection^ condb = gcnew MySqlConnection(config);
		MySqlCommand^ query = gcnew MySqlCommand("SELECT ID, Item.ItemID, Quantity, descrption FROM EquipmentTracker.location join EquipmentTracker.Item WHERE Item.ItemID = location.ItemID;", condb);

		try
		{


			MySqlDataReader^ Reader;
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = query;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bsource = gcnew BindingSource();
			bsource->DataSource = dbdataset;
			Display->DataSource = bsource;
			sda->Update(dbdataset);

		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message);
		}
	}

	
private: System::Void txtLocation_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter)
	{
		String^ config = L"datasource=127.0.0.1; port=3306; username=root; password=eggs;";
		MySqlConnection^ condb = gcnew MySqlConnection(config);
		MySqlCommand^ query = gcnew MySqlCommand("SELECT ID, Item.ItemID, Quantity, descrption FROM EquipmentTracker.location join EquipmentTracker.Item WHERE Item.ItemID = location.ItemID;", condb);

		try
		{


			MySqlDataReader^ Reader;
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = query;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bsource = gcnew BindingSource();
			bsource->DataSource = dbdataset;
			Display->DataSource = bsource;
			sda->Update(dbdataset);

		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message);
		}
	}
}
	private: System::Void Display_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) 
	{
		int rowIndex = e->RowIndex;
		DataGridViewRow^ row = Display->Rows[rowIndex];
		txtQuanity->Text = row->Cells[2]->Value->ToString();
		itemID = (int^)row->Cells[1]->Value;
		ID = (String^)row->Cells[0]->Value;
		
	}
};
};
