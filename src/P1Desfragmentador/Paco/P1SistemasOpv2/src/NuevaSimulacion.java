import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ButtonGroup;
import javax.swing.GroupLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.GroupLayout.Alignment;
import javax.swing.LayoutStyle.ComponentPlacement;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;

public class NuevaSimulacion extends JFrame {
		private JFrame ventanaEmergente;
		private JPanel contentPane;
		private JRadioButton rb1;
		private JRadioButton rb2;
		private JRadioButton rb3;
		private final ButtonGroup buttonGroup = new ButtonGroup();
		private Ventana1 ventana;
		private Ventana1 infoVentana;
		
		

		

		/**
		 * Create the frame.
		 */
		public NuevaSimulacion(Ventana1 infoVentana) {
			this.infoVentana = infoVentana;
			
			setTitle("Nueva Simulacion");
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			setBounds(100, 100, 622, 355);
			contentPane = new JPanel();
			contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
			setContentPane(contentPane);
			
			JPanel panel = new JPanel();
			panel.setBorder(new LineBorder(new Color(0, 0, 0), 4, true));
			
			//Configuracion
			
			JButton btnAceptar = new JButton("Aceptar");
			btnAceptar.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent arg0) {
					if(rb1.isSelected()) {
						//Una nueva ventana 15X30
						ventana = new Ventana1(15, 30);
						ventana.setVisible(true);
						setVisible(false);
						
					}else if (rb2.isSelected()) {
						//Una nueva ventana 10X20
						ventana = new Ventana1(10, 20);
						ventana.setVisible(true);
						setVisible(false);
						
					}else if (rb3.isSelected()) {
						ventana = new Ventana1(5, 10);
						ventana.setVisible(true);
						setVisible(false);
					}
					
					
				}
			});
			
			JButton btnNewButton = new JButton("Cancelar");
			btnNewButton.addActionListener(new ActionListener() {
				
				@Override
				public void actionPerformed(ActionEvent e) {
					setVisible(false);
					infoVentana.setVisible(true);
					
					
					
				}
			});
			GroupLayout gl_contentPane = new GroupLayout(contentPane);
			gl_contentPane.setHorizontalGroup(
				gl_contentPane.createParallelGroup(Alignment.LEADING)
					.addGroup(gl_contentPane.createSequentialGroup()
						.addGap(97)
						.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING, false)
							.addGroup(gl_contentPane.createSequentialGroup()
								.addComponent(btnAceptar, GroupLayout.PREFERRED_SIZE, 90, GroupLayout.PREFERRED_SIZE)
								.addPreferredGap(ComponentPlacement.RELATED, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
								.addComponent(btnNewButton))
							.addComponent(panel, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE))
						.addContainerGap(83, Short.MAX_VALUE))
			);
			gl_contentPane.setVerticalGroup(
				gl_contentPane.createParallelGroup(Alignment.LEADING)
					.addGroup(gl_contentPane.createSequentialGroup()
						.addGap(99)
						.addComponent(panel, GroupLayout.PREFERRED_SIZE, 84, GroupLayout.PREFERRED_SIZE)
						.addGap(48)
						.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
							.addComponent(btnAceptar, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
							.addComponent(btnNewButton, GroupLayout.PREFERRED_SIZE, 23, GroupLayout.PREFERRED_SIZE))
						.addGap(43))
			);
			
			rb1 = new JRadioButton("Matriz 15x30");
			buttonGroup.add(rb1);
			
			rb2 = new JRadioButton("Matriz 10X20");
			buttonGroup.add(rb2);
			
			rb3 = new JRadioButton("Matriz 5X10");
			buttonGroup.add(rb3);
			
			
			GroupLayout gl_panel = new GroupLayout(panel);
			gl_panel.setHorizontalGroup(
				gl_panel.createParallelGroup(Alignment.LEADING)
					.addGroup(gl_panel.createSequentialGroup()
						.addGap(27)
						.addComponent(rb1)
						.addGap(51)
						.addComponent(rb2)
						.addPreferredGap(ComponentPlacement.RELATED, 54, Short.MAX_VALUE)
						.addComponent(rb3)
						.addGap(21))
			);
			gl_panel.setVerticalGroup(
				gl_panel.createParallelGroup(Alignment.LEADING)
					.addGroup(gl_panel.createSequentialGroup()
						.addGap(31)
						.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
							.addComponent(rb1)
							.addComponent(rb2)
							.addComponent(rb3))
						.addContainerGap(22, Short.MAX_VALUE))
			);
			panel.setLayout(gl_panel);
			contentPane.setLayout(gl_contentPane);
		}
	}