package org.elsys.postfix;

import java.io.InputStream;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

import org.elsys.postfix.operations.*;

public class Calculator {

	private Map<String, Operation> operations = new HashMap<>();

	private List<Double> stack = new LinkedList<>();

	private InputStream in;

	private PrintStream out;
	
	public Calculator(InputStream in, PrintStream out) {
		this.in = in;
		this.out = out;
		addOperation(new Negate(this));
		addOperation(new Duplicate(this));
		addOperation(new Sinus(this));
		addOperation(new Cosinus(this));
		addOperation(new Multiply(this));
		addOperation(new Plus(this));
		addOperation(new Minus(this));
		addOperation(new Divide(this));
		addOperation(new MultiMin(this));
		addOperation(new Swap(this));
		addOperation(new Rotate(this));
	}

	public void run() {
		String input;
		try (Scanner scanner = new Scanner(in)) {
			while (scanner.hasNext()) {
				out.print(stack.size() + ": ");
				input = scanner.next();
				if (input.contains("\\")) {
					createComposite(input);
					continue;
				}
				if (isDouble(input)) {
					stack.add(Double.valueOf(input));
				} else {
					Operation operation = getOperation(input);
					if (operation != null) {
						operation.calculate();
					} else {
						throw new UnsupportedOperationException();
					}
				}
			}
		}
	}

	private void createComposite(String input) {
		CompositeOperation op = new CompositeOperation(this, input.substring(1));
		Scanner scanner = new Scanner(in);
		String opName;

		while (scanner.hasNext()) {
			opName = scanner.next();

			if (opName.equals("def"))
				break;

			Operation operation = getOperation(opName);
			if (operation != null) {
				op.addOperation(operation);
			}
		}

		addOperation(op);
	}

	private static boolean isDouble(String input) {
		try {
			Double.valueOf(input);
		} catch (NumberFormatException e) {
			return false;
		}
		return true;
	}

	public void addOperation(Operation operation) {
		operations.put(operation.getToken(), operation);
	}

	public Operation getOperation(String token) {
		return operations.get(token);
	}

	public Double popValue() {
		int lastIndex = stack.size() - 1;
		Double value = stack.get(lastIndex);
		stack.remove(lastIndex);
		return value;
	}

	Double lastValue() {
		return stack.get(stack.size() - 1);
	}

	public void addValue(double value) {
		out.println(value);
		stack.add(value);
	}

	public int stackSize() {
		return stack.size();
	}
}
