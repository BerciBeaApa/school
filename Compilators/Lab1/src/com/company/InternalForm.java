package com.company;

import com.google.common.collect.LinkedListMultimap;
import com.google.common.collect.Multimap;

import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;

/**
 * Created by Paul on 28.10.2015.
 */
public class InternalForm {
    private LinkedHashMap<String, Integer> atoms;
    private LinkedHashMap<String, Integer> variableSymbols;
    private LinkedHashMap<String, Integer> constantSymbols;
    private LinkedListMultimap<Integer, Integer> internalForm;

    public InternalForm() {
        atoms = new LinkedHashMap<String, Integer>();
        variableSymbols = new LinkedHashMap<String, Integer>();
        constantSymbols = new LinkedHashMap<String, Integer>();
        internalForm = LinkedListMultimap.create();
        atoms.put("Variables", 0);
        atoms.put("Constants", 1);
    }

    public String internalFormString() {
        String s = "";
        for (Map.Entry entry : internalForm.entries()) {
            s += entry.getKey() + " " + (entry.getValue() == null ? "-" : entry.getValue()) + "\n";
        }
        return s;
    }

    public void addAtoms(String key) {
        if (!atoms.containsKey(key)) {
            atoms.put(key, atoms.size());
        }
        internalForm.put(atoms.get(key), null);
    }

    public void addVariableSymbols(String key) {
        if (!variableSymbols.containsKey(key)) {
            variableSymbols.put(key, variableSymbols.size());
        }
        internalForm.put(0, variableSymbols.get(key));
    }

    public void addConstantSymbols(String key) {
        if (!constantSymbols.containsKey(key)) {
            constantSymbols.put(key, constantSymbols.size());
        }
        internalForm.put(1, constantSymbols.get(key));
    }

    public LinkedHashMap<String, Integer> getAtoms() {
        return atoms;
    }

    public void setAtoms(LinkedHashMap<String, Integer> atoms) {
        this.atoms = atoms;
    }

    public LinkedHashMap<String, Integer> getVariableSymbols() {
        return variableSymbols;
    }

    public void setVariableSymbols(LinkedHashMap<String, Integer> variableSymbols) {
        this.variableSymbols = variableSymbols;
    }

    public LinkedHashMap<String, Integer> getConstantSymbols() {
        return constantSymbols;
    }

    public void setConstantSymbols(LinkedHashMap<String, Integer> constantSymbols) {
        this.constantSymbols = constantSymbols;
    }

    public LinkedListMultimap<Integer, Integer> getInternalForm() {
        return internalForm;
    }

    public void setInternalForm(LinkedListMultimap<Integer, Integer> internalForm) {
        this.internalForm = internalForm;
    }
}
