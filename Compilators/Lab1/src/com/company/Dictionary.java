package com.company;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Paul on 28.10.2015.
 */
public class Dictionary {
    private List<String> dictionary;

    public Dictionary(String fileName) {
        dictionary = new ArrayList<String>();
        FileManager fm = new FileManager(fileName);
        dictionary = fm.splitToWords(fm.readFromFile().replaceAll("\\s+", " "));
    }

    public boolean contains(String s) {
        return dictionary.contains(s);
    }
}
