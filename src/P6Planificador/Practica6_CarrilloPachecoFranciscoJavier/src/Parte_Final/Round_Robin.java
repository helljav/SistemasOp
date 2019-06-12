package Parte_Final;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
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

public class Round_Robin extends JFrame {

	private JPanel contentPane;

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
	 */
	public Round_Robin() {
		//VENTANA PRINCIPAL
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100,980, 620);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		
		//LABEL PARA EL TITULO		
		JLabel lblPlanificadorRoundDobin = new JLabel("ALGORITMO DE PLANIFICADOR DE PROCESOS ROUND ROBIN");
		lblPlanificadorRoundDobin.setFont(new Font("Consolas", Font.BOLD, 16));
		lblPlanificadorRoundDobin.setHorizontalAlignment(SwingConstants.CENTER);
		lblPlanificadorRoundDobin.setHorizontalTextPosition(SwingConstants.CENTER);
		lblPlanificadorRoundDobin.setOpaque(true);
		lblPlanificadorRoundDobin.setBackground(UIManager.getColor("List.selectionBackground"));
		
//		PANEL PARA LA INFORMACION DE LOS PROCESOS		
		JPanel panel = new JPanel();
		panel.setBounds(10, 30, 700, 200);
		panel.setBorder(new LineBorder(new Color(0, 0, 0), 1, true));
		GroupLayout gl_contentPane = new GroupLayout(contentPane);
		gl_contentPane.setHorizontalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(Alignment.TRAILING, gl_contentPane.createSequentialGroup()
					.addContainerGap(101, Short.MAX_VALUE)
					.addComponent(lblPlanificadorRoundDobin, GroupLayout.PREFERRED_SIZE, 767, GroupLayout.PREFERRED_SIZE)
					.addGap(86))
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(42)
					.addComponent(panel, GroupLayout.PREFERRED_SIZE, 387, GroupLayout.PREFERRED_SIZE)
					.addContainerGap(525, Short.MAX_VALUE))
		);
		gl_contentPane.setVerticalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(28)
					.addComponent(lblPlanificadorRoundDobin, GroupLayout.PREFERRED_SIZE, 34, GroupLayout.PREFERRED_SIZE)
					.addGap(18)
					.addComponent(panel, GroupLayout.PREFERRED_SIZE, 226, GroupLayout.PREFERRED_SIZE)
					.addContainerGap(265, Short.MAX_VALUE))
		);
		contentPane.setLayout(gl_contentPane);
	}
}
