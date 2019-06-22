package Parte_Final;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.LinkedList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.UIManager;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;

public class Round_Robin extends JFrame implements ActionListener {
	
	/**
	 * Con esta clase se crearan objetos de tipo proceso en la cola y estos contendran la informacion de la tabla
	 */
    class Procesos {

        private int numRafagas;
        private Color color;
        private final int arribo;
        private  String name;

        public Procesos(String numRafagas, Color color, String arrivo, String name) {
            this.numRafagas = Integer.parseInt(numRafagas);
            this.color = color;
            this.arribo = Integer.parseInt(arrivo);
            this.name = name;
        }

        public int getnumRafagas() {
            return numRafagas;
        }

        public Color getColor() {
            return color;
        }

        public int getArrivo() {
            return arribo;
        }

        public String getName() {
            return name;
        }

        public void setnumRafagas(int numRafagas) {
            this.numRafagas = numRafagas;
        }
        public void setName(String Nombre) {
            this.name = Nombre;
        }
        public void setColor(Color color) {
            this.color = color;
        }
    }

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JPanel panel, panel_2, panel_1;
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
	private JButton btnNuevaSimulacion,btnComenzarSimulacion,btnEstablecerRafaga;
	private Font fuente1 = new Font("Currier New", Font.BOLD, 16);
	private Font fuente2 = new Font("Currier New", Font.BOLD, 12);
	private int tiempo;
	private boolean bandera = false;

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
				
				btnEstablecerRafaga = new JButton("ESTABLECER TIEMPO");
				btnEstablecerRafaga.setBounds(262, 307, 161, 28);
				btnEstablecerRafaga.addActionListener(this);
				
				btnNuevaSimulacion = new JButton("NUEVA SIMULACION");
				btnNuevaSimulacion.setBounds(567, 305, 155, 32);
				btnNuevaSimulacion.addActionListener(this);
				
				btnComenzarSimulacion = new JButton("COMENZAR SIMULACION");
				btnComenzarSimulacion.setBounds(739, 305, 179, 30);
				btnComenzarSimulacion.addActionListener(this);
				
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
				panel_2.setBounds(98, 348, 838, 222);
				panel_2.setLayout(new GridLayout(8, 40));
				contentPane.add(panel_2);
				
				JLabel lblRafaga = new JLabel("RAFAGA");
				lblRafaga.setHorizontalAlignment(SwingConstants.CENTER);
				lblRafaga.setFont(new Font("Consolas", Font.BOLD, 12));
				lblRafaga.setBounds(51, 354, 50, 23);
				contentPane.add(lblRafaga);
				
				JLabel labelArribo = new JLabel("ARRIBO");
				labelArribo.setHorizontalAlignment(SwingConstants.CENTER);
				labelArribo.setFont(new Font("Consolas", Font.BOLD, 12));
				labelArribo.setBounds(48, 379, 50, 23);
				contentPane.add(labelArribo);
				
				JLabel lblPlanificador = new JLabel("PLANIFICADOR");
				lblPlanificador.setHorizontalAlignment(SwingConstants.CENTER);
				lblPlanificador.setFont(new Font("Consolas", Font.BOLD, 12));
				lblPlanificador.setBounds(13, 438, 88, 23);
				contentPane.add(lblPlanificador);
				
				JLabel lblFifo = new JLabel("FIFO");
				lblFifo.setHorizontalAlignment(SwingConstants.CENTER);
				lblFifo.setFont(new Font("Consolas", Font.BOLD, 12));
				lblFifo.setBounds(50, 488, 38, 23);
				contentPane.add(lblFifo);
				info = new JLabel[n][m];
				simulacion = new JLabel[ns][ms];
				
				iniciaPanel();//Iniaciando el panel 

				
		
	}
	
	void iniciaPanel() {
		
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
				simulacion[i][j].setBackground(Color.WHITE);
				simulacion[i][j].setVisible(false);
				simulacion[i][j].setFont(fuente2);
				panel_2.add(simulacion[i][j]);				
			}
		}
		llenainfo();
		
	}
	
	void llenainfo() {
		int num;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//valores del random para que genere numeros aleatorios entre 0-10 de arrivo (j==1)
                if (i == 1) {      
                    if (j == 1) {
                        num = (int) (Math.random() * 11);
                        info[i][j].setText(num + "");
                    } else if(j==2) {//y entre 1-10 para # de rafagas (j==2)
                        num = (int) (Math.random() * 10) + 1;
                        info[i][j].setText(num + "");
                    }
                }
                if (i == 2) {
                    if (j == 1) {
                        num = (int) (Math.random() * 11);
                        info[i][j].setText(num + "");
                    } else if(j==2){
                        num = (int) (Math.random() * 10) + 1;
                        info[i][j].setText(num + "");
                    }
                    
                }
                if (i == 3) {
                    if (j == 1) {
                        num = (int) (Math.random() * 11);
                        info[i][j].setText(num + "");
                    } else if(j==2) {
                        num = (int) (Math.random() * 10) + 1;
                        info[i][j].setText(num + "");
                    }
                    

                }
                if (i == 4) {
                    if (j == 1) {
                        num = (int) (Math.random() * 11);
                        info[i][j].setText(num + "");
                    } else if(j==2) {
                        num = (int) (Math.random() * 10) + 1;
                        info[i][j].setText(num + "");
                    }
                }
            
                panel.add(info[i][j]);
				
			}
			
		}
	}
	
	
	void nuevaSimulacion() {
		for (int i = 0; i < ns; i++) {
			for (int j = 0; j < ms; j++) {
				simulacion[i][j].setText("");;
				simulacion[i][j].setBackground(Color.WHITE);
				simulacion[i][j].setVisible(false);				
			}
		}			
		textRafaga.setText("");
		textEspera.setText("");
		textRespuesta.setText("");
		bandera = false;
		llenainfo();		
	}
	
	
	void iniciaSimulacion() {
		int sumaRafagas;
		int pedazo =0;
		Procesos p1 = new Procesos( info[1][2].getText(),info[1][2].getBackground(),info[1][1].getText(),"p1");
		Procesos p2 = new Procesos( info[2][2].getText(),info[2][2].getBackground(),info[2][1].getText(),"p2");
		Procesos p3 = new Procesos( info[3][2].getText(),info[3][2].getBackground(),info[3][1].getText(),"p3");
		Procesos p4 = new Procesos( info[4][2].getText(),info[4][2].getBackground(),info[4][1].getText(),"p4");
		
		LinkedList<Procesos> FIFO = new LinkedList();   //cola de procesos
		LinkedList<Procesos> FIFOSalida = new LinkedList();   //cola de procesos cuya rafagas hayan sido terminadas
		
		
		Procesos pActual = new Procesos("-1", Color.WHITE, "-1", "PA");
        Procesos pSalida = new Procesos("-1", Color.WHITE, "-1", "PA");
        
        boolean pvalidado = false;
        int contadorFIFO =4;
		
		sumaRafagas = p1.getnumRafagas() + p2.getnumRafagas() + p3.getnumRafagas() + p4.getnumRafagas();
		//Pinta solo una parte de toda la simulacion
		for (int i = 0; i <ns; i++) {
			for (int j = 0; j < 40; j++) {
				simulacion[i][j].setVisible(true);
				
			}
			
		}
		
//		Cada iteracion de i en el for es un pedazo de rafaga   
		for (int i = 0; i < 40; i++) {
			
			simulacion[0][i].setText(String.valueOf(i+1));//rafagas en el area de simulacion			
			//Solo pinta el arribo y encola en ese punto 
			 if (p1.getArrivo()  == i) {
                 FIFO.add(p1);
                 simulacion[1][i].setText("P1");
                 simulacion[1][i].setForeground(Color.WHITE);
                 simulacion[1][i].setBackground(Color.BLACK);
                 //System.out.println("Arribo :"+FIFO.indexOf(p1));
             }
             if (p2.getArrivo()  == i) {
                 FIFO.add(p2);
                 simulacion[1][i].setText("P2");
                 simulacion[1][i].setForeground(Color.WHITE);
                 simulacion[1][i].setBackground(Color.BLACK);
             }
             if (p3.getArrivo() == i) {
                 FIFO.add(p3);
                 simulacion[1][i].setText("P3");
                 simulacion[1][i].setForeground(Color.WHITE);
                 simulacion[1][i].setBackground(Color.BLACK);
             }
             if (p4.getArrivo() == i) {
                 FIFO.add(p4);
                 simulacion[1][i].setText("P4");
                 simulacion[1][i].setForeground(Color.WHITE);
                 simulacion[1][i].setBackground(Color.BLACK);
             }
           if(pedazo==tiempo) {
        	   pedazo=0;
        	   if(FIFO.size()>0) {
        		  if(pvalidado == true) {
        			  pActual = FIFO.remove();
        			  FIFO.addLast(pActual);
        			  pActual = FIFO.removeFirst();
        			  pvalidado = false;
        		  }
        		  else {
        			  pActual = FIFO.removeFirst();
        		  }
        	   }
           }else if(FIFO.size()>0) {
        	   pActual = FIFO.removeFirst();
           }
           if(pActual.getnumRafagas()>0) {
        	   simulacion[2][i].setText(pActual.getName());
        	   simulacion[3][i].setBackground(pActual.getColor());
	           pActual.setnumRafagas(pActual.getnumRafagas()-1);
	           pedazo++;
           }
           if(pActual.getnumRafagas()>0) {
        	   FIFO.addFirst(pActual);
        	   pvalidado = true;
           }
           
          
  			
 			
  			for (int j = 0; j < FIFO.size(); j++) {
  				simulacion[contadorFIFO][i].setText(pActual.getName());
  				contadorFIFO++;
				
			}
  			contadorFIFO =4;
 			 
			
		}
		
		
		
		

	}
	
	
	
		
	
	/**
	 * Eventos para los botones
	 * (Personalidad)
	 */
	@Override//captura todas las acciones de los botones y realiza la funcion de cada uno
		public void actionPerformed(ActionEvent e) {
			if (e.getSource() == btnNuevaSimulacion ) {
				nuevaSimulacion();
			}else if(e.getSource()==btnComenzarSimulacion) {
				if(bandera ==false) {
					JOptionPane.showMessageDialog(null, "Establesca una rafaga de tiempo primero");
				}
				else {
					try {
						tiempo = Integer.parseInt(textRafaga.getText());
						if(tiempo<1||tiempo>10) {
							JOptionPane.showMessageDialog(null, "Ingrese un numero del 1 al 10");
						}
						else {
							iniciaSimulacion();
						}
					}catch(Exception e2) {
						JOptionPane.showMessageDialog(null, "Ingrese un numero valido del 1 al 10");
					}
				}
				
			}else if(e.getSource()==btnEstablecerRafaga) {
				if(textRafaga.getText().isEmpty()) {
					JOptionPane.showMessageDialog(null, "Establezca una rafaga de tiempo primero");					
				}
				else {
					bandera = true;
				}
			}
		}
		
	
}
