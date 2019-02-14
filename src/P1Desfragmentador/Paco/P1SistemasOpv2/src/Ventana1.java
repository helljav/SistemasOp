/**
 * Las clases siguientes, son clases de ayuda para realizar la primera prctica de
 * la materia de sistemass operativos 19I
 */

import java.awt.Color;
import java.awt.Cursor;
import java.awt.Event;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Random;

import javax.swing.BorderFactory;
import javax.swing.ButtonGroup;
import javax.swing.GroupLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.KeyStroke;
import javax.swing.Timer;
import javax.swing.GroupLayout.Alignment;
import javax.swing.LayoutStyle.ComponentPlacement;
import javax.swing.border.Border;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;

/**
*
* @author Francisco Javier Carrillo Pacheco
*/

public final class Ventana1 extends JFrame implements ActionListener {

	private JButton[][] casilla;//Matriz de botones
	private final Object[][][] Tablero;//Tablero tridimencional de dos capas (digitos y colores ), Nos servira para manipular todo
	private JButton jbutton1;
	private JButton jbutton2;
	private JButton jbutton3;
	private JMenuBar barra_Menu;
	private JMenu menu;
	private JMenuItem nuevaSimulacion;
	private JMenuItem salir;
	private JPanel Panel_Matriz;
	private final Color[] colores;
	private Timer timer;
	/**
	 * Clase cola_de_digitos
	 * Esta clase nos ayudara a crear listas, que contendran como informacion
	 * toda una columna de digitos y su respactivo color.
	 * El implements Serializable, permitira a la clase comportance como una lista
	 * @author Francisco Javier 
	 *
	 */
	class cola_de_Digitos implements Serializable {
		Random na = new Random();
		Random na2 = new Random();
		int nai, naj;
		private final Color color;//Color de la primera ilera de colores
		private int n_digitos = na.nextInt(((n*m)/5))+3;//Este valor debe de ser aleatorio por cada color entre 2 a (#total de casillas/#de colores) que es el numero de fragmentos que tendra un color
		/**
		 * Contsructor de la clase cola_de_Digitos
		 * @param color: Color de  cada columna
		 * @param digito: Se inicia con 1 para ir aumentando en el for del constructor hasta n_digitos generados 
		 */
		public cola_de_Digitos(Color color, int digito) {
			//System.out.println(n_digitos);
			this.color = color;
			boolean flag = false;
			for(int i=0;i<n_digitos;i++) {
				do {
					nai = na.nextInt(n);
					naj = na2.nextInt(m);
					if((int)Tablero[0][nai][naj]!=0) {
						flag=true;																
					}
					else {
						Tablero[0][nai][naj] = digito++;//Se le asigna los digitos por color
						casilla[nai][naj].setText(String.valueOf(Tablero[0][nai][naj]));//Esos mismos digitos los tendran los botones
						Tablero[1][nai][naj] = color;//Se le asigna un color al fragmento
						casilla[nai][naj].setBackground(color);//Ese color tambien se le asigna al boton
						casilla[nai][naj].setForeground(Color.BLACK);
						casilla[nai][naj].setBorder(new javax.swing.border.LineBorder(Color.BLACK));
						flag=false;
					}					
				} while (flag);
			}
		}
	}// Cierra cola_de_Digitos

	
	//IMPORTANTE: Estos son los fragmentos
	//Se configura en inicia digitos
	protected ArrayList<cola_de_Digitos> candado;
	protected int n, m;//Filas y columnas de la matriz (10,5)
	
	
	
	/**
	 * Constructor de los fragmentos
	 * @param n: filas
	 * @param m: Columnas
	 */	
	public Ventana1(int n, int m) {
		this.n = n;
		this.m = m;
		Tablero = new Object[2][n][m];//Se crean las capas		
		colores = new Color[5];//Se crea una arreglo de colores (una por cada columna)
		colores[0] = Color.YELLOW;
		colores[1] = Color.RED;
		colores[2] = Color.ORANGE;
		colores[3] = Color.LIGHT_GRAY;
		colores[4] = Color.blue;
		iniciaComponentes();
	}

	
	/**
	 * Este metodo inica y configura los componentes graficos 
	 */
	public void iniciaComponentes() {
		setLayout(null);
		setTitle("Desfragmentador");
		Font fuente = new Font("Arial", Font.BOLD, 12);
		casilla = new JButton[n][m];
		Panel_Matriz = new JPanel();
		Panel_Matriz.setFont(fuente);
		
		Panel_Matriz.setBorder(BorderFactory.createTitledBorder("Simulacion: Desfragmentador"));
		Panel_Matriz.setBounds(0, 0, 1077, 560);
		Panel_Matriz.setLayout(new GridLayout(n, m));
		Panel_Matriz.setVisible(true);
		
		iniciaDigitos(n, m);//Importante 
		getContentPane().add(Panel_Matriz);

		fuente = new Font("Arial", Font.BOLD, 16);
		jbutton1 = new JButton("Desfragmentado");
		jbutton1.setFont(fuente);
		jbutton1.addActionListener(this);//Se le agrega la personalidad al primer boton
		
		jbutton2 = new JButton("Nueva Fragmentacion");
		jbutton2.setFont(fuente);
		jbutton2.addActionListener(this);//Se le agrega la personalidad al segundo boton
		
		jbutton3 = new JButton("Salir");
		jbutton3.setFont(fuente);
		jbutton3.addActionListener(this);//Se le agrega la personalidad al tercer boton
		
		barra_Menu = new JMenuBar();
		menu = new JMenu("Simulador");
		menu.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
		barra_Menu.add(menu);
		
		
		nuevaSimulacion = new JMenuItem("Nueva Simulacion");
		nuevaSimulacion.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
		nuevaSimulacion.addActionListener(this);
		nuevaSimulacion.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_F2, ActionEvent.CTRL_MASK));//Atajo
		menu.add(nuevaSimulacion);
		
		
		salir = new JMenuItem("Salir");
		salir.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
		salir.addActionListener(this);
		salir.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_F5, ActionEvent.CTRL_MASK));//Atajo
		
		menu.add(salir);
		
		setBounds(0, 0, 1100, 660);//Ventana principal
		
		
		jbutton1.setBounds(50, 560, 170, 30);
		this.add(jbutton1);
		jbutton2.setBounds(420, 560, 210, 30);
		this.add(jbutton2);
		jbutton3.setBounds(850, 560, 110, 30);
		this.add(jbutton3);
		
		this.setJMenuBar(barra_Menu);
		setSize(1080,660);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
		setLocationRelativeTo(null);
	}
	
	
	
	
	/**
	 * Metodo inicia digitos en el tablero y en los botones
	 * @param i: Numero de filas 
	 * @param j: Numero de columnas 
	 */
	public void iniciaDigitos(int i, int j) {
		Font fuente = new Font("Serif", Font.BOLD, 14);
		//En la capa de digitos, la inicializa en cero y en la capa de color las inicializa en blanco
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				Tablero[0][i][j] = 0;
				Tablero[1][i][j] = Color.WHITE;
			}
		}
		//Configura la matriz de botones, dejandolos en color blanco y configurando el texto de los mismos
		//Despues los agrega en el Panel_Matriz
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				casilla[i][j] = new JButton("");
				casilla[i][j].setFont(fuente);
				casilla[i][j].setBackground(Color.WHITE);
				casilla[i][j].setForeground(Color.BLACK);
				casilla[i][j].addActionListener(this);
				casilla[i][j].setBorder(new javax.swing.border.LineBorder(Color.BLACK));
				Panel_Matriz.add(casilla[i][j]);
			}
		}
		
		//Se le otorga color y los digitos, tanto a las capas como a los botones
		candado = new ArrayList<>(5);
		for (i = 0; i < 5; i++) {
			cola_de_Digitos obj = new cola_de_Digitos(colores[i], 1);
			candado.add(obj);
		}
	}// Cierra iniciaDigitos
	
	
	
	
/**
 * Eventos para los botones
 * (Personalidad)
 */
	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == jbutton1) {
			comienzaSimulacion();
		} else if (e.getSource() == jbutton2) {
			nuevaSimulacion();
		} else if (e.getSource() == jbutton3) {
			System.exit(0);
		}else if(e.getSource()==nuevaSimulacion) {
			NuevaSimulacion vN = new NuevaSimulacion(this);
			vN.setVisible(true);
			vN.setLocationRelativeTo(null);
			setVisible(false);
			
		}else if(e.getSource()==salir) {
			System.exit(0);
		}
	}
	
	
	
	
	/**
	 * comienzaSimulacion
	 */
	private void comienzaSimulacion() {
		ArrayList<Integer> arraux1 = new ArrayList<>();
		ArrayList<Integer> arraux2 = new ArrayList<>();
		ArrayList<Integer> arraux3 = new ArrayList<>();
		ArrayList<Integer> arraux4 = new ArrayList<>();
		ArrayList<Integer> arraux5 = new ArrayList<>();
		ArrayList<Integer> General = new ArrayList<>();
		ArrayList<Color> Generalcolor = new ArrayList<>();
		for (int k = 0; k < 5; k++) {
			for(int i =0; i<n;i++) {
				for (int j = 0; j < m; j++) {
					if(Tablero[1][i][j]==colores[k]) {
						if(k==0) {
							arraux1.add((int)Tablero[0][i][j]);
							Generalcolor.add(Color.YELLOW);
						}else if(k==1) {
							arraux2.add((int)Tablero[0][i][j]);
							Generalcolor.add(Color.RED);
						}else if (k==2) {
							arraux3.add((int)Tablero[0][i][j]);
							Generalcolor.add(Color.ORANGE);
						}else if(k==3) {
							arraux4.add((int)Tablero[0][i][j]);
							Generalcolor.add(Color.LIGHT_GRAY);
						}else if(k==4) {
							arraux5.add((int)Tablero[0][i][j]);
							Generalcolor.add(Color.blue);
						}
						
											
					}
				}
			}
			
		}
		Collections.sort(arraux1);
		Collections.sort(arraux2);
		Collections.sort(arraux3);
		Collections.sort(arraux4);
		Collections.sort(arraux5);
		
		for (int k = 0; k < 5; k++) {
			if(k==0) {
				for (int i = 0; i < arraux1.size(); i++) {
					General.add(arraux1.get(i));
					
				}
			}
			if(k==1) {
				for (int i = 0; i < arraux2.size(); i++) {
					General.add(arraux2.get(i));
					
				}
			}
			if(k==2) {
				for (int i = 0; i < arraux3.size(); i++) {
					General.add(arraux3.get(i));
					
				}
			}
			if(k==3) {
				for (int i = 0; i < arraux4.size(); i++) {
					General.add(arraux4.get(i));
					
				}
			}
			if(k==4) {
				for (int i = 0; i < arraux5.size(); i++) {
					General.add(arraux5.get(i));
					
				}
			}											
				
		}
		System.out.println("Pauta");
		
		for(int i=0; i<General.size();i++) {
			System.out.println(General.get(i));
		}
		int contador =0;
		for(int i =0; i<n;i++) {
			for (int j = 0; j < m; j++) {
				try {
					casilla[i][j].setBackground(Generalcolor.get(contador));
					casilla[i][j].setText(String.valueOf(General.get(contador)));
					Tablero[0][i][j] = General.get(contador);
					Tablero[1][i][j] = Generalcolor.get(contador);
					contador++;
					
				} catch (Exception e) {
					// TODO: handle exception
					casilla[i][j].setText("");
					casilla[i][j].setBackground(Color.WHITE);
					Tablero[0][i][j] = 0;
					Tablero[1][i][j] = Color.WHITE;
				}
						
					
				}
			}
		
			

	}// Cierra comienza Simulacion

	
	public void nuevaSimulacion() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				Tablero[0][i][j] = 0;
				Tablero[1][i][j] = Color.WHITE;
			}
		}

		// Empieza la declaracion del tablero mediante un for doble
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// Reiniciamos las etiquetas
				casilla[i][j].setText("");
				// Establcer el color para el fondo de casilla
				casilla[i][j].setBackground(Color.WHITE);
				// Establece un color para el texto de casilla
				casilla[i][j].setForeground(Color.BLACK);
			}
		}

		// Inicializamos el arreglo para los archivos que seran desfragmentados
		candado = new ArrayList<>(5);
		for (int i = 0; i < 5; i++) {
			cola_de_Digitos obj = new cola_de_Digitos(colores[i], 1);
			candado.add(obj);

		}
	}// cierra nuevaSimulacion
	
	
	


	public static void main(String[] args) {
		java.awt.EventQueue.invokeLater(() -> {
			new Ventana1(15, 30).setVisible(true);
		});
	}
}
