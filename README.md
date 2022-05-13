# PW-Gruppo2-LovelyCommy
Project Work 2022 Gruppo 2 Corso Diqu
Faraoni Matteo, Gatto Alessandro, Pizzato Davide, Scapolan Davide

<mxfile host="app.diagrams.net" modified="2022-05-13T15:38:14.501Z" agent="5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/101.0.4951.64 Safari/537.36" etag="8U0otYTJFS4c7WauBrb4" version="18.0.3" type="github">
  <diagram id="x0fFBpjRPYXEMjXJBNxW" name="Page-1">
    <mxGraphModel dx="1038" dy="521" grid="1" gridSize="10" guides="1" tooltips="1" connect="1" arrows="1" fold="1" page="1" pageScale="1" pageWidth="827" pageHeight="1169" math="0" shadow="0">
      <root>
        <mxCell id="0" />
        <mxCell id="1" parent="0" />
        <mxCell id="DjnAWuUxVTk70V278BnW-2" value="CLOUD" style="verticalAlign=top;align=left;spacingTop=8;spacingLeft=2;spacingRight=12;shape=cube;size=10;direction=south;fontStyle=4;html=1;rounded=0;shadow=0;comic=0;labelBackgroundColor=none;strokeWidth=1;fontFamily=Verdana;fontSize=12" vertex="1" parent="1">
          <mxGeometry x="260" width="330" height="220" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-3" value="Raspberry PI" style="verticalAlign=top;align=left;spacingTop=8;spacingLeft=2;spacingRight=12;shape=cube;size=10;direction=south;fontStyle=4;html=1;rounded=0;shadow=0;comic=0;labelBackgroundColor=none;strokeWidth=1;fontFamily=Verdana;fontSize=12" vertex="1" parent="1">
          <mxGeometry x="260" y="280" width="330" height="270" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-4" value="&lt;font style=&quot;font-size: 13px;&quot;&gt;RS485&lt;/font&gt;" style="edgeStyle=orthogonalEdgeStyle;rounded=0;orthogonalLoop=1;jettySize=auto;html=1;entryX=1;entryY=0.5;entryDx=0;entryDy=0;entryPerimeter=0;strokeWidth=2;startArrow=classic;startFill=1;" edge="1" parent="1" source="DjnAWuUxVTk70V278BnW-5" target="DjnAWuUxVTk70V278BnW-3">
          <mxGeometry relative="1" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-5" value="uC" style="verticalAlign=top;align=left;spacingTop=8;spacingLeft=2;spacingRight=12;shape=cube;size=10;direction=south;fontStyle=4;html=1;rounded=0;shadow=0;comic=0;labelBackgroundColor=none;strokeWidth=1;fontFamily=Verdana;fontSize=12" vertex="1" parent="1">
          <mxGeometry x="260" y="610" width="330" height="220" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-6" value="AMQP" style="edgeStyle=orthogonalEdgeStyle;rounded=0;orthogonalLoop=1;jettySize=auto;html=1;entryX=0.5;entryY=1;entryDx=0;entryDy=0;startArrow=classic;startFill=1;" edge="1" parent="1" source="DjnAWuUxVTk70V278BnW-8" target="DjnAWuUxVTk70V278BnW-19">
          <mxGeometry relative="1" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-7" style="edgeStyle=orthogonalEdgeStyle;rounded=0;orthogonalLoop=1;jettySize=auto;html=1;exitX=1;exitY=0.5;exitDx=0;exitDy=0;entryX=0;entryY=0.75;entryDx=0;entryDy=0;startArrow=none;startFill=0;" edge="1" parent="1" source="DjnAWuUxVTk70V278BnW-8" target="DjnAWuUxVTk70V278BnW-27">
          <mxGeometry relative="1" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-8" value="Interprete&lt;br&gt;Seriale" style="shape=component;align=left;spacingLeft=36;rounded=0;shadow=0;comic=0;labelBackgroundColor=none;strokeWidth=1;fontFamily=Verdana;fontSize=12;html=1;" vertex="1" parent="1">
          <mxGeometry x="365" y="420" width="120" height="60" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-9" style="edgeStyle=orthogonalEdgeStyle;rounded=0;orthogonalLoop=1;jettySize=auto;html=1;entryX=0.443;entryY=0.98;entryDx=0;entryDy=0;entryPerimeter=0;" edge="1" parent="1" source="DjnAWuUxVTk70V278BnW-11" target="DjnAWuUxVTk70V278BnW-12">
          <mxGeometry relative="1" as="geometry">
            <Array as="points">
              <mxPoint x="425" y="670" />
              <mxPoint x="425" y="670" />
            </Array>
          </mxGeometry>
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-10" style="edgeStyle=orthogonalEdgeStyle;rounded=0;orthogonalLoop=1;jettySize=auto;html=1;entryX=0;entryY=0.462;entryDx=0;entryDy=0;entryPerimeter=0;startArrow=none;startFill=0;" edge="1" parent="1" source="DjnAWuUxVTk70V278BnW-11" target="DjnAWuUxVTk70V278BnW-15">
          <mxGeometry relative="1" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-11" value="Lettura e &lt;br&gt;interpretazione &lt;br&gt;segnali" style="shape=component;align=left;spacingLeft=36;rounded=0;shadow=0;comic=0;labelBackgroundColor=none;strokeWidth=1;fontFamily=Verdana;fontSize=12;html=1;" vertex="1" parent="1">
          <mxGeometry x="360" y="690" width="130" height="60" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-12" value="&lt;span style=&quot;font-family: Verdana; text-align: left;&quot;&gt;Custom&amp;nbsp;&lt;/span&gt;&lt;span style=&quot;font-family: Verdana; text-align: left;&quot;&gt;protocol&lt;/span&gt;" style="rounded=0;whiteSpace=wrap;html=1;" vertex="1" parent="1">
          <mxGeometry x="300" y="620" width="280" height="40" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-13" style="edgeStyle=orthogonalEdgeStyle;rounded=0;orthogonalLoop=1;jettySize=auto;html=1;entryX=0.5;entryY=1;entryDx=0;entryDy=0;startArrow=none;startFill=0;exitX=0.513;exitY=-0.046;exitDx=0;exitDy=0;exitPerimeter=0;" edge="1" parent="1" source="DjnAWuUxVTk70V278BnW-14" target="DjnAWuUxVTk70V278BnW-11">
          <mxGeometry relative="1" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-14" value="Sensori" style="rounded=0;whiteSpace=wrap;html=1;" vertex="1" parent="1">
          <mxGeometry x="260" y="790" width="320" height="40" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-15" value="Display" style="rounded=0;whiteSpace=wrap;html=1;" vertex="1" parent="1">
          <mxGeometry x="510" y="670" width="60" height="110" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-16" style="edgeStyle=orthogonalEdgeStyle;rounded=0;orthogonalLoop=1;jettySize=auto;html=1;entryX=0.5;entryY=1;entryDx=0;entryDy=0;startArrow=classic;startFill=1;exitX=0.515;exitY=-0.048;exitDx=0;exitDy=0;exitPerimeter=0;" edge="1" parent="1" source="DjnAWuUxVTk70V278BnW-17" target="DjnAWuUxVTk70V278BnW-8">
          <mxGeometry relative="1" as="geometry">
            <Array as="points" />
          </mxGeometry>
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-17" value="Custom protocol" style="rounded=0;whiteSpace=wrap;html=1;" vertex="1" parent="1">
          <mxGeometry x="260" y="510" width="320" height="40" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-18" value="&lt;font style=&quot;font-size: 13px;&quot;&gt;MQTT&lt;/font&gt;" style="edgeStyle=orthogonalEdgeStyle;rounded=0;orthogonalLoop=1;jettySize=auto;html=1;entryX=0.909;entryY=0.5;entryDx=0;entryDy=0;entryPerimeter=0;startArrow=classic;startFill=1;strokeWidth=2;" edge="1" parent="1" source="DjnAWuUxVTk70V278BnW-19" target="DjnAWuUxVTk70V278BnW-2">
          <mxGeometry relative="1" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-19" value="Interprete&lt;br&gt;AMQP&lt;br&gt;(connection&lt;br&gt;check)" style="shape=component;align=left;spacingLeft=36;rounded=0;shadow=0;comic=0;labelBackgroundColor=none;strokeWidth=1;fontFamily=Verdana;fontSize=12;html=1;" vertex="1" parent="1">
          <mxGeometry x="365" y="320" width="120" height="60" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-20" value="&lt;font style=&quot;font-size: 15px;&quot;&gt;Telemetria&lt;/font&gt;" style="endArrow=classic;html=1;rounded=0;dashed=1;strokeWidth=3;" edge="1" parent="1">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="220" y="650" as="sourcePoint" />
            <mxPoint x="220" y="150" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-21" value="&lt;font style=&quot;font-size: 15px;&quot;&gt;Comandi&lt;/font&gt;" style="endArrow=classic;html=1;rounded=0;dashed=1;strokeWidth=3;" edge="1" parent="1">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="630" y="150" as="sourcePoint" />
            <mxPoint x="630" y="650" as="targetPoint" />
            <mxPoint y="-1" as="offset" />
          </mxGeometry>
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-22" style="edgeStyle=orthogonalEdgeStyle;rounded=0;orthogonalLoop=1;jettySize=auto;html=1;exitX=0.459;exitY=-0.003;exitDx=0;exitDy=0;entryX=0.5;entryY=1;entryDx=0;entryDy=0;startArrow=classic;startFill=1;exitPerimeter=0;" edge="1" parent="1" source="DjnAWuUxVTk70V278BnW-23" target="DjnAWuUxVTk70V278BnW-26">
          <mxGeometry relative="1" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-23" value="MQTT&lt;br&gt;Broker" style="shape=component;align=left;spacingLeft=36;rounded=0;shadow=0;comic=0;labelBackgroundColor=none;strokeWidth=1;fontFamily=Verdana;fontSize=12;html=1;" vertex="1" parent="1">
          <mxGeometry x="365" y="140" width="120" height="60" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-24" value="UI" style="rounded=0;whiteSpace=wrap;html=1;" vertex="1" parent="1">
          <mxGeometry x="270" y="40" width="40" height="170" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-25" style="edgeStyle=orthogonalEdgeStyle;rounded=0;orthogonalLoop=1;jettySize=auto;html=1;entryX=1;entryY=0.241;entryDx=0;entryDy=0;entryPerimeter=0;startArrow=classic;startFill=1;" edge="1" parent="1" source="DjnAWuUxVTk70V278BnW-26" target="DjnAWuUxVTk70V278BnW-24">
          <mxGeometry relative="1" as="geometry">
            <Array as="points">
              <mxPoint x="310" y="80" />
            </Array>
          </mxGeometry>
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-26" value="Web App" style="shape=component;align=left;spacingLeft=36;rounded=0;shadow=0;comic=0;labelBackgroundColor=none;strokeWidth=1;fontFamily=Verdana;fontSize=12;html=1;" vertex="1" parent="1">
          <mxGeometry x="360" y="50" width="120" height="60" as="geometry" />
        </mxCell>
        <mxCell id="DjnAWuUxVTk70V278BnW-27" value="Display" style="rounded=0;whiteSpace=wrap;html=1;" vertex="1" parent="1">
          <mxGeometry x="500" y="300" width="70" height="200" as="geometry" />
        </mxCell>
      </root>
    </mxGraphModel>
  </diagram>
</mxfile>
