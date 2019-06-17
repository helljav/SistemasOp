package Parte_Final;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.BorderFactory;
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JTable;
import javax.swing.JLabel;
import javax.swing.UIManager;
import java.awt.Color;
import javax.swing.SwingConstants;
import java.awt.Font;
import javax.swing.border.LineBorder;
import java.awt.Dimension;
import java.awt.GridLayout;
import javax.swing.border.TitledBorder;
import javax.swing.LayoutStyle.ComponentPlacement;
import javax.swing.JTextField;
import javax.swing.JButton;

public class Round_Robin extends JFrame {

	private JPanel contentPane;
	private JPanel panel;
	private JPanel panel_2;
	private JPanel panel_1;
	private JLabel[][] info;
	private JLabel[][] simulacion;
	private int n=5;//filas procesos
	private int m=3;//Columnas procesos
	
	private int ns = 8;//filas simulacion
	private int ms = 40;//Columnas simulacion
	private JTextField textEspera;
	private JTextField textRespuesta;
	private JTextField textField;
	private JTextField textRafaga;
	private Font fuente1 = new Font("Consolas", Font.BOLD, 16);
	private Font fuente2 = new Font("Consolas", Font.BOLD, 12);

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Round_Robin frame = new Round_Robin();
					frame.setVisible(true);
					frame.setLocationRelativeTo(null);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 * Cosntructor, a qui se inicializaran los componentes en estandar
	 */
	public Round_Robin() {
		iniciaComponentes();
		
			
	}
	
	public void iniciaComponentes() {
		//VENTANA PRINCIPAL
				setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				setBounds(100, 100,980, 620);
				contentPane = new JPanel();
				contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
				setContentPane(contentPane);
				
				//LABEL PARA EL TITULO		
				JLabel lblPlanificadorRoundDobin = new JLabel("ALGORITMO DE PLANIFICADOR DE PROCESOS ROUND ROBIN");
				lblPlanificadorRoundDobin.setBounds(73, 33, 767, 34);
				lblPlanificadorRoundDobin.setFont(fuente1);
				lblPlanificadorRoundDobin.setHorizontalAlignment(SwingConstants.CENTER);
				lblPlanificadorRoundDobin.setHorizontalTextPosition(SwingConstants.CENTER);
				lblPlanificadorRoundDobin.setOpaque(true);
				lblPlanificadorRoundDobin.setBackground(UIManager.getColor("List.selectionBackground"));
				
				
//				PANEL PARA LA INFORMACION DE LOS PROCESOS		
				panel = new JPanel();
				panel.setBounds(38, 85, 533, 209);
				
				panel_1 = new JPanel();
				panel_1.setBounds(602, 81, 316, 213);
				panel_1.setBorder(UIManager.getBorder("Spinner.border"));
				
				JLabel lblTiempoR = new JLabel("PEDAZO DE TIEMPO: ");
				lblTiempoR.setBounds(41, 305, 148, 38);
				lblTiempoR.setFont(fuente2);
				lblTiempoR.setHorizontalAlignment(SwingConstants.CENTER);
				
				textRafaga = new JTextField();
				textRafaga.setBounds(176, 305, 76, 32);
				textRafaga.setColumns(10);
				
				JButton btnEstablecerRafaga = new JButton("ESTABLECER TIEMPO");
				btnEstablecerRafaga.setBounds(262, 307, 161, 28);
				
				JButton btnNuevaSimulacion = new JButton("NUEVA SIMULACION");
				btnNuevaSimulacion.setBounds(567, 305, 155, 32);
				
				JButton btnComenzarSimulacion = new JButton("COMENZAR SIMULACION");
				btnComenzarSimulacion.setBounds(739, 305, 179, 30);
				
				JLabel lblEspera = new JLabel("TIEMPO PROMEDIO DE ESPERA");
				lblEspera.setBounds(13, 3, 280, 35);
				lblEspera.setFont(fuente2);
				lblEspera.setHorizontalAlignment(SwingConstants.CENTER);
				
				textEspera = new JTextField();
				textEspera.setBounds(23, 44, 280, 24);
				textEspera.setEnabled(false);
				textEspera.setColumns(10);
				
				JLabel labelRespuesta = new JLabel("TIEMPO PROMEDIO DE RESPUESTA");
				labelRespuesta.setBounds(23, 74, 280, 35);
				labelRespuesta.setHorizontalAlignment(SwingConstants.CENTER);
				labelRespuesta.setFont(fuente2);
				
				textRespuesta = new JTextField();
				textRespuesta.setBounds(23, 115, 280, 24);
				textRespuesta.setEnabled(false);
				textRespuesta.setColumns(10);
				
				JLabel labelProcesos = new JLabel("NUMERO DE CAMBIOS DE PROCESOS");
				labelProcesos.setBounds(23, 145, 280, 35);
				labelProcesos.setHorizontalAlignment(SwingConstants.CENTER);
				labelProcesos.setFont(fuente2);
				
				textField = new JTextField();
				textField.setBounds(23, 178, 280, 24);
				textField.setEnabled(false);
				textField.setColumns(10);
				panel.setLayout(new GridLayout(5, 3));
				panel.setBorder(UIManager.getBorder("TextField.border"));
				contentPane.setLayout(null);
				contentPane.add(lblPlanificadorRoundDobin);
				contentPane.add(panel);
				contentPane.add(textRafaga);
				contentPane.add(btnEstablecerRafaga);
				contentPane.add(btnNuevaSimulacion);
				contentPane.add(btnComenzarSimulacion);
				contentPane.add(panel_1);
				panel_1.setLayout(null);
				panel_1.add(textEspera);
				panel_1.add(labelRespuesta);
				panel_1.add(textRespuesta);
				panel_1.add(labelProcesos);
				panel_1.add(textField);
				panel_1.add(lblEspera);
				contentPane.add(lblTiempoR);
				
				panel_2 = new JPanel();
				panel_2.setBounds(81, 348, 837, 222);
				panel_2.setLayout(new GridLayout(8, 40));
				contentPane.add(panel_2);
				
				JLabel lblRafaga = new JLabel("RAFAGA");
				lblRafaga.setHorizontalAlignment(SwingConstants.CENTER);
				lblRafaga.setFont(new Font("Consolas", Font.BOLD, 12));
				lblRafaga.setBounds(25, 354, 63, 23);
				contentPane.add(lblRafaga);
				info = new JLabel[n][m];
				simulacion = new JLabel[ns][ms];
				
				simulacion();//Iniaciando la simulacio

				
		
	}
	
	void simulacion() {
		
		//Lennando de los primeros componentes que cuentan con la informacion
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 3; j++) {
				info[i][j] = new JLabel("");
				info[i][j].setBorder(new LineBorder(new Color(0, 0, 0), 1, true));
				info[i][j].setOpaque(true);
				if(i==0) {
					info[i][j].setBackground(UIManager.getColor("List.selectionBackground"));
				}
				if(i==1) {
					info[i][j].setBackground(Color.yellow);					
				}
				if(i==2) {
					info[i][j].setBackground(Color.blue);					
				}
				if(i==3) {
					info[i][j].setBackground(Color.red);					
				}
				if(i==4) {
					info[i][j].setBackground(Color.gray);					
				}
				panel.add(info[i][j]);				
			}
		}
		
		info[0][0].setText("PROCESOS");
		info[1][0].setText("P1");
		info[2][0].setText("P2");
		info[3][0].setText("P3");
		info[4][0].setText("P4");
		info[0][1].setText("TIEMPO DE ARRIBO/LLEGADA");
		info[0][2].setText("RAFAGAS DE USO DEL CPU");
		
		//llenado donde estara la simulacion		
		for (int i = 0; i < ns; i++) {
			for (int j = 0; j < ms; j++) {
				simulacion[i][j] = new JLabel("");
				simulacion[i][j].setBorder(new LineBorder(new Color(0, 0, 0), 1, true));
				simulacion[i][j].setOpaque(true);
				//simulacion[i][j].setVisible(false);
				simulacion[i][j].setFont(fuente2);
				panel_2.add(simulacion[i][j]);				
			}
		}
		
	}
}
