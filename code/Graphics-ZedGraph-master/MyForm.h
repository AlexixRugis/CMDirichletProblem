#pragma once

#include <cmath>
#include <climits>
#include <cfloat>
#include <string>
#include <chrono>
#include "Functions.h"
#include "Problem.h"
#include "SeidelSolver.h"
#include "SORSolver.h"

namespace Graph {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace ZedGraph;
    using namespace CMDirichlet;

    /// <summary>
    /// Summary for MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form {
    public:
        MyForm(void) {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~MyForm() {
            if (components) {
                delete components;
            }
        }

    protected:
    private: System::Windows::Forms::TabPage^ tabPage1;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
    private: System::Windows::Forms::TextBox^ a_textbox;
    private: System::Windows::Forms::TextBox^ b_textbox;
    private: System::Windows::Forms::TextBox^ d_textbox;
    private: System::Windows::Forms::TextBox^ c_textbox;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::TextBox^ n_textbox;
    private: System::Windows::Forms::TextBox^ m_textbox;
    private: System::Windows::Forms::TextBox^ nmax_textbox;
    private: System::Windows::Forms::TextBox^ epsn_textbox;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::TextBox^ w_textbox;
    private: System::Windows::Forms::Label^ label10;
    private: System::Windows::Forms::Label^ label11;
    private: System::Windows::Forms::Label^ label12;
    private: System::Windows::Forms::ComboBox^ method_combobox;
    private: System::Windows::Forms::ComboBox^ problem_combobox;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::GroupBox^ problem2_groupbox;
    private: System::Windows::Forms::DataGridView^ u_solution_grid;
    private: System::Windows::Forms::GroupBox^ problem1_groupbox;
    private: System::Windows::Forms::DataGridView^ v_solution_grid;
    private: System::Windows::Forms::GroupBox^ problem_diff_groupbox;
    private: System::Windows::Forms::DataGridView^ delta_solution_grid;
    private: System::Windows::Forms::TabControl^ tabControl1;
    private: System::Windows::Forms::TabPage^ tabPage2;
    private: System::Windows::Forms::Label^ label13;
    private: System::Windows::Forms::TextBox^ eps2n_textbox;

    private: System::Windows::Forms::Label^ label14;
    private: System::Windows::Forms::TextBox^ w2_textbox;
    private: System::Windows::Forms::Label^ label15;





































































































































































































































    protected:
    private: System::ComponentModel::IContainer^ components;

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>


#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void) {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->a_textbox = (gcnew System::Windows::Forms::TextBox());
            this->b_textbox = (gcnew System::Windows::Forms::TextBox());
            this->d_textbox = (gcnew System::Windows::Forms::TextBox());
            this->c_textbox = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->n_textbox = (gcnew System::Windows::Forms::TextBox());
            this->m_textbox = (gcnew System::Windows::Forms::TextBox());
            this->nmax_textbox = (gcnew System::Windows::Forms::TextBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->method_combobox = (gcnew System::Windows::Forms::ComboBox());
            this->problem_combobox = (gcnew System::Windows::Forms::ComboBox());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->w2_textbox = (gcnew System::Windows::Forms::TextBox());
            this->w_textbox = (gcnew System::Windows::Forms::TextBox());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->epsn_textbox = (gcnew System::Windows::Forms::TextBox());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->eps2n_textbox = (gcnew System::Windows::Forms::TextBox());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->problem2_groupbox = (gcnew System::Windows::Forms::GroupBox());
            this->u_solution_grid = (gcnew System::Windows::Forms::DataGridView());
            this->problem1_groupbox = (gcnew System::Windows::Forms::GroupBox());
            this->v_solution_grid = (gcnew System::Windows::Forms::DataGridView());
            this->problem_diff_groupbox = (gcnew System::Windows::Forms::GroupBox());
            this->delta_solution_grid = (gcnew System::Windows::Forms::DataGridView());
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->tabPage1->SuspendLayout();
            this->tableLayoutPanel1->SuspendLayout();
            this->tableLayoutPanel2->SuspendLayout();
            this->tableLayoutPanel3->SuspendLayout();
            this->tableLayoutPanel4->SuspendLayout();
            this->problem2_groupbox->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->u_solution_grid))->BeginInit();
            this->problem1_groupbox->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->v_solution_grid))->BeginInit();
            this->problem_diff_groupbox->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->delta_solution_grid))->BeginInit();
            this->tabControl1->SuspendLayout();
            this->tabPage2->SuspendLayout();
            this->SuspendLayout();
            // 
            // tabPage1
            // 
            this->tabPage1->Controls->Add(this->tableLayoutPanel1);
            this->tabPage1->Location = System::Drawing::Point(4, 22);
            this->tabPage1->Margin = System::Windows::Forms::Padding(2);
            this->tabPage1->Name = L"tabPage1";
            this->tabPage1->Padding = System::Windows::Forms::Padding(2);
            this->tabPage1->Size = System::Drawing::Size(1344, 702);
            this->tabPage1->TabIndex = 0;
            this->tabPage1->Text = L"Решение задачи";
            this->tabPage1->UseVisualStyleBackColor = true;
            // 
            // tableLayoutPanel1
            // 
            this->tableLayoutPanel1->ColumnCount = 2;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->problem2_groupbox, 1, 0);
            this->tableLayoutPanel1->Controls->Add(this->problem1_groupbox, 0, 1);
            this->tableLayoutPanel1->Controls->Add(this->problem_diff_groupbox, 1, 1);
            this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel1->Location = System::Drawing::Point(2, 2);
            this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(2);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 2;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 16)));
            this->tableLayoutPanel1->Size = System::Drawing::Size(1340, 698);
            this->tableLayoutPanel1->TabIndex = 0;
            // 
            // tableLayoutPanel2
            // 
            this->tableLayoutPanel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutPanel2->ColumnCount = 1;
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 1);
            this->tableLayoutPanel2->Controls->Add(this->label1, 0, 0);
            this->tableLayoutPanel2->Location = System::Drawing::Point(2, 2);
            this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(2);
            this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
            this->tableLayoutPanel2->RowCount = 2;
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 72.16982F)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 27.83019F)));
            this->tableLayoutPanel2->Size = System::Drawing::Size(666, 345);
            this->tableLayoutPanel2->TabIndex = 3;
            // 
            // tableLayoutPanel3
            // 
            this->tableLayoutPanel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutPanel3->ColumnCount = 2;
            this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                77.32426F)));
            this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                22.67574F)));
            this->tableLayoutPanel3->Controls->Add(this->button1, 1, 0);
            this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 0, 0);
            this->tableLayoutPanel3->Location = System::Drawing::Point(2, 250);
            this->tableLayoutPanel3->Margin = System::Windows::Forms::Padding(2);
            this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
            this->tableLayoutPanel3->RowCount = 1;
            this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 93)));
            this->tableLayoutPanel3->Size = System::Drawing::Size(662, 93);
            this->tableLayoutPanel3->TabIndex = 1;
            // 
            // button1
            // 
            this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->button1->Location = System::Drawing::Point(549, 52);
            this->button1->Margin = System::Windows::Forms::Padding(2);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(111, 39);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Решить задачу";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // tableLayoutPanel4
            // 
            this->tableLayoutPanel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutPanel4->ColumnCount = 8;
            this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                12.07863F)));
            this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                5.128205F)));
            this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                14.7929F)));
            this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                11.43984F)));
            this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                15.58185F)));
            this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                17.55424F)));
            this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                11.63708F)));
            this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                13.60947F)));
            this->tableLayoutPanel4->Controls->Add(this->a_textbox, 0, 0);
            this->tableLayoutPanel4->Controls->Add(this->b_textbox, 0, 1);
            this->tableLayoutPanel4->Controls->Add(this->d_textbox, 0, 3);
            this->tableLayoutPanel4->Controls->Add(this->c_textbox, 0, 2);
            this->tableLayoutPanel4->Controls->Add(this->label2, 1, 0);
            this->tableLayoutPanel4->Controls->Add(this->label3, 1, 1);
            this->tableLayoutPanel4->Controls->Add(this->label4, 1, 2);
            this->tableLayoutPanel4->Controls->Add(this->label5, 1, 3);
            this->tableLayoutPanel4->Controls->Add(this->n_textbox, 2, 0);
            this->tableLayoutPanel4->Controls->Add(this->m_textbox, 2, 1);
            this->tableLayoutPanel4->Controls->Add(this->nmax_textbox, 2, 2);
            this->tableLayoutPanel4->Controls->Add(this->label6, 3, 0);
            this->tableLayoutPanel4->Controls->Add(this->label7, 3, 1);
            this->tableLayoutPanel4->Controls->Add(this->label8, 3, 2);
            this->tableLayoutPanel4->Controls->Add(this->label10, 5, 0);
            this->tableLayoutPanel4->Controls->Add(this->label12, 5, 2);
            this->tableLayoutPanel4->Controls->Add(this->method_combobox, 4, 0);
            this->tableLayoutPanel4->Controls->Add(this->problem_combobox, 4, 2);
            this->tableLayoutPanel4->Controls->Add(this->label15, 7, 1);
            this->tableLayoutPanel4->Controls->Add(this->w2_textbox, 6, 1);
            this->tableLayoutPanel4->Controls->Add(this->w_textbox, 6, 0);
            this->tableLayoutPanel4->Controls->Add(this->label11, 7, 0);
            this->tableLayoutPanel4->Controls->Add(this->epsn_textbox, 6, 2);
            this->tableLayoutPanel4->Controls->Add(this->label9, 7, 2);
            this->tableLayoutPanel4->Controls->Add(this->eps2n_textbox, 6, 3);
            this->tableLayoutPanel4->Controls->Add(this->label14, 7, 3);
            this->tableLayoutPanel4->Location = System::Drawing::Point(2, 2);
            this->tableLayoutPanel4->Margin = System::Windows::Forms::Padding(2);
            this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
            this->tableLayoutPanel4->RowCount = 4;
            this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel4->Size = System::Drawing::Size(507, 89);
            this->tableLayoutPanel4->TabIndex = 1;
            // 
            // a_textbox
            // 
            this->a_textbox->Location = System::Drawing::Point(2, 2);
            this->a_textbox->Margin = System::Windows::Forms::Padding(2);
            this->a_textbox->Name = L"a_textbox";
            this->a_textbox->Size = System::Drawing::Size(56, 20);
            this->a_textbox->TabIndex = 0;
            // 
            // b_textbox
            // 
            this->b_textbox->Location = System::Drawing::Point(2, 24);
            this->b_textbox->Margin = System::Windows::Forms::Padding(2);
            this->b_textbox->Name = L"b_textbox";
            this->b_textbox->Size = System::Drawing::Size(56, 20);
            this->b_textbox->TabIndex = 1;
            // 
            // d_textbox
            // 
            this->d_textbox->Location = System::Drawing::Point(2, 68);
            this->d_textbox->Margin = System::Windows::Forms::Padding(2);
            this->d_textbox->Name = L"d_textbox";
            this->d_textbox->Size = System::Drawing::Size(56, 20);
            this->d_textbox->TabIndex = 3;
            // 
            // c_textbox
            // 
            this->c_textbox->Location = System::Drawing::Point(2, 46);
            this->c_textbox->Margin = System::Windows::Forms::Padding(2);
            this->c_textbox->Name = L"c_textbox";
            this->c_textbox->Size = System::Drawing::Size(56, 20);
            this->c_textbox->TabIndex = 4;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(62, 0);
            this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(13, 13);
            this->label2->TabIndex = 5;
            this->label2->Text = L"a";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(62, 22);
            this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(13, 13);
            this->label3->TabIndex = 6;
            this->label3->Text = L"b";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(62, 44);
            this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(13, 13);
            this->label4->TabIndex = 7;
            this->label4->Text = L"c";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(62, 66);
            this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(13, 13);
            this->label5->TabIndex = 8;
            this->label5->Text = L"d";
            // 
            // n_textbox
            // 
            this->n_textbox->Location = System::Drawing::Point(87, 2);
            this->n_textbox->Margin = System::Windows::Forms::Padding(2);
            this->n_textbox->Name = L"n_textbox";
            this->n_textbox->Size = System::Drawing::Size(69, 20);
            this->n_textbox->TabIndex = 9;
            // 
            // m_textbox
            // 
            this->m_textbox->Location = System::Drawing::Point(87, 24);
            this->m_textbox->Margin = System::Windows::Forms::Padding(2);
            this->m_textbox->Name = L"m_textbox";
            this->m_textbox->Size = System::Drawing::Size(69, 20);
            this->m_textbox->TabIndex = 10;
            // 
            // nmax_textbox
            // 
            this->nmax_textbox->Location = System::Drawing::Point(87, 46);
            this->nmax_textbox->Margin = System::Windows::Forms::Padding(2);
            this->nmax_textbox->Name = L"nmax_textbox";
            this->nmax_textbox->Size = System::Drawing::Size(69, 20);
            this->nmax_textbox->TabIndex = 11;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(160, 0);
            this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(13, 13);
            this->label6->TabIndex = 13;
            this->label6->Text = L"n";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(160, 22);
            this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(15, 13);
            this->label7->TabIndex = 14;
            this->label7->Text = L"m";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Location = System::Drawing::Point(160, 44);
            this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(34, 13);
            this->label8->TabIndex = 15;
            this->label8->Text = L"Nmax";
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Location = System::Drawing::Point(293, 0);
            this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(51, 22);
            this->label10->TabIndex = 20;
            this->label10->Text = L"Метод решения";
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->Location = System::Drawing::Point(293, 44);
            this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(43, 13);
            this->label12->TabIndex = 22;
            this->label12->Text = L"Задача";
            // 
            // method_combobox
            // 
            this->method_combobox->FormattingEnabled = true;
            this->method_combobox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Зейделя", L"МВР" });
            this->method_combobox->Location = System::Drawing::Point(216, 2);
            this->method_combobox->Margin = System::Windows::Forms::Padding(2);
            this->method_combobox->Name = L"method_combobox";
            this->method_combobox->Size = System::Drawing::Size(73, 21);
            this->method_combobox->TabIndex = 23;
            // 
            // problem_combobox
            // 
            this->problem_combobox->FormattingEnabled = true;
            this->problem_combobox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Тестовая", L"Основная" });
            this->problem_combobox->Location = System::Drawing::Point(216, 46);
            this->problem_combobox->Margin = System::Windows::Forms::Padding(2);
            this->problem_combobox->Name = L"problem_combobox";
            this->problem_combobox->Size = System::Drawing::Size(73, 21);
            this->problem_combobox->TabIndex = 24;
            // 
            // label15
            // 
            this->label15->AutoSize = true;
            this->label15->Location = System::Drawing::Point(438, 22);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(21, 13);
            this->label15->TabIndex = 28;
            this->label15->Text = L"w2";
            // 
            // w2_textbox
            // 
            this->w2_textbox->Location = System::Drawing::Point(381, 25);
            this->w2_textbox->Name = L"w2_textbox";
            this->w2_textbox->Size = System::Drawing::Size(51, 20);
            this->w2_textbox->TabIndex = 27;
            // 
            // w_textbox
            // 
            this->w_textbox->Location = System::Drawing::Point(380, 2);
            this->w_textbox->Margin = System::Windows::Forms::Padding(2);
            this->w_textbox->Name = L"w_textbox";
            this->w_textbox->Size = System::Drawing::Size(53, 20);
            this->w_textbox->TabIndex = 19;
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Location = System::Drawing::Point(437, 0);
            this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(15, 13);
            this->label11->TabIndex = 21;
            this->label11->Text = L"w";
            // 
            // epsn_textbox
            // 
            this->epsn_textbox->Location = System::Drawing::Point(380, 46);
            this->epsn_textbox->Margin = System::Windows::Forms::Padding(2);
            this->epsn_textbox->Name = L"epsn_textbox";
            this->epsn_textbox->Size = System::Drawing::Size(53, 20);
            this->epsn_textbox->TabIndex = 12;
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Location = System::Drawing::Point(437, 44);
            this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(38, 13);
            this->label9->TabIndex = 16;
            this->label9->Text = L"eps_N";
            // 
            // eps2n_textbox
            // 
            this->eps2n_textbox->Location = System::Drawing::Point(381, 69);
            this->eps2n_textbox->Name = L"eps2n_textbox";
            this->eps2n_textbox->Size = System::Drawing::Size(51, 20);
            this->eps2n_textbox->TabIndex = 25;
            // 
            // label14
            // 
            this->label14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label14->AutoSize = true;
            this->label14->Location = System::Drawing::Point(438, 66);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(66, 13);
            this->label14->TabIndex = 26;
            this->label14->Text = L"eps_2N";
            // 
            // label1
            // 
            this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(2, 0);
            this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(662, 248);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Здесь появится справка о решении задачи";
            // 
            // problem2_groupbox
            // 
            this->problem2_groupbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->problem2_groupbox->Controls->Add(this->u_solution_grid);
            this->problem2_groupbox->Location = System::Drawing::Point(672, 2);
            this->problem2_groupbox->Margin = System::Windows::Forms::Padding(2);
            this->problem2_groupbox->Name = L"problem2_groupbox";
            this->problem2_groupbox->Padding = System::Windows::Forms::Padding(2);
            this->problem2_groupbox->Size = System::Drawing::Size(666, 345);
            this->problem2_groupbox->TabIndex = 4;
            this->problem2_groupbox->TabStop = false;
            this->problem2_groupbox->Text = L"u*(x,y)";
            // 
            // u_solution_grid
            // 
            this->u_solution_grid->BackgroundColor = System::Drawing::SystemColors::ControlLight;
            this->u_solution_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->u_solution_grid->Dock = System::Windows::Forms::DockStyle::Fill;
            this->u_solution_grid->Location = System::Drawing::Point(2, 15);
            this->u_solution_grid->Margin = System::Windows::Forms::Padding(2);
            this->u_solution_grid->Name = L"u_solution_grid";
            this->u_solution_grid->RowHeadersWidth = 51;
            this->u_solution_grid->RowTemplate->Height = 24;
            this->u_solution_grid->Size = System::Drawing::Size(662, 328);
            this->u_solution_grid->TabIndex = 0;
            // 
            // problem1_groupbox
            // 
            this->problem1_groupbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->problem1_groupbox->Controls->Add(this->v_solution_grid);
            this->problem1_groupbox->Location = System::Drawing::Point(2, 351);
            this->problem1_groupbox->Margin = System::Windows::Forms::Padding(2);
            this->problem1_groupbox->Name = L"problem1_groupbox";
            this->problem1_groupbox->Padding = System::Windows::Forms::Padding(2);
            this->problem1_groupbox->Size = System::Drawing::Size(666, 345);
            this->problem1_groupbox->TabIndex = 5;
            this->problem1_groupbox->TabStop = false;
            this->problem1_groupbox->Text = L"v*(x, y)";
            // 
            // v_solution_grid
            // 
            this->v_solution_grid->BackgroundColor = System::Drawing::SystemColors::ControlLight;
            this->v_solution_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->v_solution_grid->Dock = System::Windows::Forms::DockStyle::Fill;
            this->v_solution_grid->Location = System::Drawing::Point(2, 15);
            this->v_solution_grid->Margin = System::Windows::Forms::Padding(2);
            this->v_solution_grid->Name = L"v_solution_grid";
            this->v_solution_grid->RowHeadersWidth = 51;
            this->v_solution_grid->RowTemplate->Height = 24;
            this->v_solution_grid->Size = System::Drawing::Size(662, 328);
            this->v_solution_grid->TabIndex = 0;
            // 
            // problem_diff_groupbox
            // 
            this->problem_diff_groupbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->problem_diff_groupbox->Controls->Add(this->delta_solution_grid);
            this->problem_diff_groupbox->Location = System::Drawing::Point(672, 351);
            this->problem_diff_groupbox->Margin = System::Windows::Forms::Padding(2);
            this->problem_diff_groupbox->Name = L"problem_diff_groupbox";
            this->problem_diff_groupbox->Padding = System::Windows::Forms::Padding(2);
            this->problem_diff_groupbox->Size = System::Drawing::Size(666, 345);
            this->problem_diff_groupbox->TabIndex = 6;
            this->problem_diff_groupbox->TabStop = false;
            this->problem_diff_groupbox->Text = L"u* - v*";
            // 
            // delta_solution_grid
            // 
            this->delta_solution_grid->BackgroundColor = System::Drawing::SystemColors::ControlLight;
            this->delta_solution_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->delta_solution_grid->Dock = System::Windows::Forms::DockStyle::Fill;
            this->delta_solution_grid->Location = System::Drawing::Point(2, 15);
            this->delta_solution_grid->Margin = System::Windows::Forms::Padding(2);
            this->delta_solution_grid->Name = L"delta_solution_grid";
            this->delta_solution_grid->RowHeadersWidth = 51;
            this->delta_solution_grid->RowTemplate->Height = 24;
            this->delta_solution_grid->Size = System::Drawing::Size(662, 328);
            this->delta_solution_grid->TabIndex = 0;
            // 
            // tabControl1
            // 
            this->tabControl1->Controls->Add(this->tabPage1);
            this->tabControl1->Controls->Add(this->tabPage2);
            this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tabControl1->Location = System::Drawing::Point(0, 0);
            this->tabControl1->Margin = System::Windows::Forms::Padding(2);
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->Size = System::Drawing::Size(1352, 728);
            this->tabControl1->TabIndex = 31;
            // 
            // tabPage2
            // 
            this->tabPage2->Controls->Add(this->label13);
            this->tabPage2->Location = System::Drawing::Point(4, 22);
            this->tabPage2->Margin = System::Windows::Forms::Padding(2);
            this->tabPage2->Name = L"tabPage2";
            this->tabPage2->Size = System::Drawing::Size(1344, 702);
            this->tabPage2->TabIndex = 1;
            this->tabPage2->Text = L"Описание задач";
            this->tabPage2->UseVisualStyleBackColor = true;
            // 
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label13->Location = System::Drawing::Point(0, 0);
            this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label13->Name = L"label13";
            this->label13->Padding = System::Windows::Forms::Padding(8);
            this->label13->Size = System::Drawing::Size(369, 400);
            this->label13->TabIndex = 0;
            this->label13->Text = resources->GetString(L"label13.Text");
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1352, 728);
            this->Controls->Add(this->tabControl1);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->tabPage1->ResumeLayout(false);
            this->tableLayoutPanel1->ResumeLayout(false);
            this->tableLayoutPanel2->ResumeLayout(false);
            this->tableLayoutPanel2->PerformLayout();
            this->tableLayoutPanel3->ResumeLayout(false);
            this->tableLayoutPanel4->ResumeLayout(false);
            this->tableLayoutPanel4->PerformLayout();
            this->problem2_groupbox->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->u_solution_grid))->EndInit();
            this->problem1_groupbox->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->v_solution_grid))->EndInit();
            this->problem_diff_groupbox->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->delta_solution_grid))->EndInit();
            this->tabControl1->ResumeLayout(false);
            this->tabPage2->ResumeLayout(false);
            this->tabPage2->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        a_textbox->Text = "-1.0";
        b_textbox->Text = "1.0";
        c_textbox->Text = "-1.0";
        d_textbox->Text = "1.0";

        epsn_textbox->Text = "1e-9";
        eps2n_textbox->Text = "1e-11";

        n_textbox->Text = "10";
        m_textbox->Text = "10";

        nmax_textbox->Text = "20000";

        w_textbox->Text = "1.8";
        w2_textbox->Text = "1.9";
        method_combobox->SelectedIndex = 0;
        problem_combobox->SelectedIndex = 0;
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

        double a, b, c, d;
        double epsn, eps2n, w, w2;
        size_t n, m, nmax;

        try {

            a = Convert::ToDouble(NormalizeText(a_textbox->Text));
            b = Convert::ToDouble(NormalizeText(b_textbox->Text));
            c = Convert::ToDouble(NormalizeText(c_textbox->Text));
            d = Convert::ToDouble(NormalizeText(d_textbox->Text));
            epsn = Convert::ToDouble(NormalizeText(epsn_textbox->Text));
            eps2n = Convert::ToDouble(NormalizeText(eps2n_textbox->Text));
            w = Convert::ToDouble(NormalizeText(w_textbox->Text));
            w2 = Convert::ToDouble(NormalizeText(w2_textbox->Text));

            n = Convert::ToUInt64(n_textbox->Text->Trim());
            m = Convert::ToUInt64(m_textbox->Text->Trim());
            nmax = Convert::ToUInt64(nmax_textbox->Text->Trim());

            if (n == 0 || m == 0 || nmax == 0) {
                MessageBox::Show("Параметры n, m, Nmax должны быть больше 0",
                    "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            if (epsn <= 0) {
                MessageBox::Show("eps_N должно быть больше 0",
                    "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            if (eps2n <= 0) {
                MessageBox::Show("eps_2N должно быть больше 0",
                    "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            if (a >= b || c >= d) {
                MessageBox::Show("Должно быть a < b и c < d",
                    "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            if (method_combobox->SelectedIndex == 1 && (w <= 0 || w >= 2)) {
                MessageBox::Show("Для МВР метода w должно быть в интервале (0, 2)",
                    "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            if (method_combobox->SelectedIndex == 1 && (w2 <= 0 || w2 >= 2)) {
                MessageBox::Show("Для МВР метода w2 должно быть в интервале (0, 2)",
                    "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }
        }
        catch (FormatException^) {
            MessageBox::Show("Ошибка: проверьте формат введённых данных.\n"
                "Используйте точку или запятую для разделения дробной части.",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }
        catch (OverflowException^) {
            MessageBox::Show("Ошибка: значение выходит за допустимые пределы",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ошибка: " + ex->Message,
                "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        if (problem_combobox->SelectedIndex == 0) {
            DirichletProblem problem(
                n, m, a, b, c, d,
                func_f_test,
                func_mu1_test,
                func_mu2_test,
                func_mu3_test,
                func_mu4_test
            );

            double time;
            const auto solution = Solve(problem, nmax, epsn, w, time);
            const auto& v = solution.v;

            std::vector<double> u(solution.v.size(), 0.0);
            std::vector<double> diff_u_v(solution.v.size(), 0.0);

            for (size_t j = 0; j <= problem.m(); j++) {
                for (size_t i = 0; i <= problem.n(); i++) {
                    size_t index = j * (problem.n() + 1) + i;
                    u[index] = func_u_test(problem.x(i), problem.y(j));
                }
            }

            double eps_1 = 0.0;
            double eps_x = 0.0;
            double eps_y = 0.0;

            for (size_t j = 0; j <= problem.m(); j++) {
                for (size_t i = 0; i <= problem.n(); i++) {
                    size_t index = j * (problem.n() + 1) + i;
                    diff_u_v[index] = u[index] - v[index];

                    if (abs(diff_u_v[index]) > eps_1) {
                        eps_1 = abs(diff_u_v[index]);
                        eps_x = problem.x(i);
                        eps_y = problem.y(j);
                    }
                }
            }

            String^ hint = String::Format(R"(Для решения тестовой задачи использованы сетка с числом разбиений по x
n = «{0}» и числом разбиений по y m = «{1}»,
метод Зейделя, применены критерии
остановки по точности eps_мет = «{2}» и по числу итераций Nmax = «{3}»
На решение схемы(СЛАУ) затрачено итераций N = «{4}» и достигнута точность итерационного метода ε
(N)
= «{5}»
Невязка нач. прибл. || R(0) || = «{10}»
Схема(СЛАУ) решена с невязкой || R(N) || = «{6}»
для невязки СЛАУ использована норма «норма «max»;
Задача решена с погрешностью eps_1 = «{7}»
Максимальное отклонение точного и численного решений наблюдается в узле x = «{8}»; y = «{9}»
В качестве начального приближения использовано «интерполяция по x»)",
problem.n(), problem.m(), epsn, nmax,
solution.n, solution.eps, solution.r_norm,
eps_1, eps_x, eps_y, solution.r0_norm);

            label1->Text = hint;

            problem1_groupbox->Text = "v*(x,y)";
            problem2_groupbox->Text = "u*(x,y)";
            problem_diff_groupbox->Text = "u* - v*";
            /*FillDataGridViewFromSolution(v_solution_grid,
                problem.n(), problem.m(), problem.a(), problem.b(), problem.c(), problem.d(), v, 6);
            FillDataGridViewFromSolution(u_solution_grid,
                problem.n(), problem.m(), problem.a(), problem.b(), problem.c(), problem.d(), u, 6);
            FillDataGridViewFromSolution(delta_solution_grid,
                problem.n(), problem.m(), problem.a(), problem.b(), problem.c(), problem.d(), diff_u_v, 6);*/

            MessageBox::Show("Вычисления выполнены за: " + time + " секунд.",
                "Уведомление", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            DirichletProblem problem(
                n, m, a, b, c, d,
                func_f_main,
                func_mu1_main,
                func_mu2_main,
                func_mu3_main,
                func_mu4_main
            );

            DirichletProblem problem2(
                2 * n, 2 * m, a, b, c, d,
                func_f_main,
                func_mu1_main,
                func_mu2_main,
                func_mu3_main,
                func_mu4_main
            );

            double time_1, time_2;
            const auto solution = Solve(problem, nmax, epsn, w, time_1);
            const auto& v = solution.v;
            const auto solution2 = Solve(problem2, nmax, eps2n, w2, time_2);
            const auto& v2 = solution2.v;

            std::vector<double> diff_v_v2(solution.v.size(), 0.0);

            double eps_1 = 0.0;
            double eps_x = 0.0;
            double eps_y = 0.0;

            for (size_t j = 0; j <= problem.m(); j++) {
                for (size_t i = 0; i <= problem.n(); i++) {
                    size_t index = j * (problem.n() + 1) + i;
                    size_t index2 = 2 * j * (2 * problem.n() + 1) + 2 * i;
                    diff_v_v2[index] = v[index] - v2[index2];

                    if (abs(diff_v_v2[index]) > eps_1) {
                        eps_1 = abs(diff_v_v2[index]);
                        eps_x = problem.x(i);
                        eps_y = problem.y(j);
                    }
                }
            }

            String^ hint = String::Format(R"(Для решения основной задачи использована сетка с числом разбиений по x
n = «{0}» и числом разбиений по y m = «{1}», применены критерии остановки по точности eps_мет = «{2}»
и по числу итераций Nmax =«{3}».
На решение схемы (СЛАУ) затрачено итераций N = «{4}» и достигнута точность итерационного метода eps_N = «{5}»
Невязка нач. прибл. || R(0) || = «{14}»
Схема (СЛАУ) решена с невязкой || R(N)|| = «{6}»
использована норма «норма «max»
Для контроля точности решения использована сетка с половинным шагом, критерий остановки по точности eps2_мет = «{13}»
На решение задачи (СЛАУ) затрачено итераций N2 =«{7}» и достигнута точность итерационного метода eps_N2 = «{8}»
Невязка нач. прибл. || R2(0) || = «{15}»
Схема (СЛАУ) на сетке с половинным шагом решена с невязкой || R(N2) || = «{9}»
использована норма «норма «max»
Задача решена с точностью eps2 =«{10}»
Максимальное отклонение численных решений на основной сетке и сетке с
половинным шагом наблюдается в узле x=«{11}»; y=«{12}»
В качестве начального приближения на основной и дополнительной сетке использовано «интерполяция по x»)",
problem.n(), problem.m(), epsn, nmax,
solution.n, solution.eps, solution.r_norm,
solution2.n, solution2.eps, solution2.r_norm,
eps_1, eps_x, eps_y, eps2n, solution.r0_norm, solution2.r0_norm);

            label1->Text = hint;

            problem1_groupbox->Text = "v(x,y)";
            FillDataGridViewFromSolution(v_solution_grid,
                problem.n(), problem.m(), problem.a(), problem.b(), problem.c(), problem.d(), v, 6);
            problem2_groupbox->Text = "v2(x,y)";
            FillDataGridViewFromSolution(u_solution_grid,
                problem.n(), problem.m(), problem.a(), problem.b(), problem.c(), problem.d(), v2, 6);
            problem_diff_groupbox->Text = "v - v2";
            FillDataGridViewFromSolution(delta_solution_grid,
                problem.n(), problem.m(), problem.a(), problem.b(), problem.c(), problem.d(), diff_v_v2, 6);
        }
    }

    private:
        void FillDataGridView(DataGridView^ dataGridView,
            const std::vector<double>& x,
            const std::vector<double>& y,
            const std::vector<double>& solution,
            int precision) {

            if (!dataGridView || x.empty() || y.empty() || solution.empty())
                return;

            dataGridView->SuspendLayout();
            dataGridView->Visible = false;

            size_t n = x.size() - 1;
            size_t m = y.size() - 1;
            size_t rows = m + 1;
            size_t cols = n + 1;

            dataGridView->Rows->Clear();
            dataGridView->Columns->Clear();

            dataGridView->RowHeadersVisible = false;
            dataGridView->AllowUserToAddRows = false;
            dataGridView->AllowUserToDeleteRows = false;
            dataGridView->ReadOnly = true;
            dataGridView->RowHeadersWidth = 60;
            dataGridView->ColumnHeadersHeight = 40;

            DataGridViewTextBoxColumn^ headerCol = gcnew DataGridViewTextBoxColumn();
            headerCol->Name = L"Header";
            headerCol->HeaderText = L"x / y";
            headerCol->Width = 60;
            headerCol->ReadOnly = true;
            dataGridView->Columns->Add(headerCol);


            for (size_t i = 0; i <= n; i++) {
                DataGridViewTextBoxColumn^ col = gcnew DataGridViewTextBoxColumn();
                col->Name = String::Format("x_{0}", i);
                col->HeaderText = String::Format("x_{0} = {1}", i, x[i].ToString());
                col->Width = 90;
                col->ReadOnly = true;
                dataGridView->Columns->Add(col);
            }

            for (size_t j = 0; j <= m; j++) {
                DataGridViewRow^ row = gcnew DataGridViewRow();
                row->Height = 25;

                dataGridView->Rows->Add();

                dataGridView->Rows[j]->Cells[0]->Value = String::Format("y_{0} = {1}", j, y[j].ToString());

                for (size_t i = 0; i <= n; i++) {
                    DataGridViewTextBoxCell^ cell = gcnew DataGridViewTextBoxCell();
                    double value = solution[j * (n + 1) + i];
                    dataGridView->Rows[j]->Cells[i + 1]->Value = value.ToString();
                }
            }

            dataGridView->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);
            dataGridView->AutoResizeRows(DataGridViewAutoSizeRowsMode::AllCells);

            dataGridView->Visible = true;
            dataGridView->ResumeLayout();
            dataGridView->Refresh();
        }

        void FillDataGridViewFromSolution(DataGridView^ dataGridView,
            size_t n, size_t m,
            double a, double b, double c, double d,
            const std::vector<double>& solution,
            int precision) {
            std::vector<double> x(n + 1);
            std::vector<double> y(m + 1);

            double h = (b - a) / n;
            double k = (d - c) / m;

            for (size_t i = 0; i <= n; i++)
                x[i] = a + i * h;

            for (size_t j = 0; j <= m; j++)
                y[j] = c + j * k;

            FillDataGridView(dataGridView, x, y, solution, precision);
        }

        DiricletProblemSolution Solve(const DirichletProblem& problem, size_t nmax, double epsn, double w, double& time_secs) {

            auto start = std::chrono::high_resolution_clock::now();
            DiricletProblemSolution solution;
            if (method_combobox->SelectedIndex == 0) {
                SeidelSolver solver(nmax, epsn);
                solution = solver.solve(problem);
            }
            else {
                SORSolver solver(nmax, epsn, w);
                solution = solver.solve(problem);
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            time_secs = static_cast<double>(duration.count()) * 1e-3;

            return solution;
        }

        String^ NormalizeText(String^ text) {
            return text->Trim()->Replace(".", ",");
        }
    };
}
