package com.kwp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

import android.os.Bundle;
import android.os.Message;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.os.Handler;

public class MainActivity extends AppCompatActivity {
    public boolean start;
    public static final String SERVERIP = "127.0.0.1";
    public static final int SERVERPORT = 4444;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView textView = (TextView) findViewById(R.id.hello);

        String hello = KidsWatchLib.getStringFromJNI();
        textView.setText(hello);

        KidsWatchLib kidsWatchLib = new KidsWatchLib();
//        kidsWatchLib

        kidsWatchLib.login("340721198812204530");
    }


}
