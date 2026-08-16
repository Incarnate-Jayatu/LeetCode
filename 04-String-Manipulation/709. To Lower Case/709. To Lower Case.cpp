    for(int i = 0; i < ch.length; i++) {
        if(ch[i] >= 'A' && ch[i] <= 'Z')
            ch[i] = (char)(ch[i]+32);
    }
    return new String(ch);//or we can write here. s = new String(ch); means we are char Array converting into String bcuz we hava to return String
}